# NOTE: This port requires flex and bison to be installed on the system
# Windows: choco install winflexbison3
# macOS: brew install flex bison
# Linux: apt install flex bison

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO lusipad/matiec-cmake
    REF 17dc930dd6a43857dc787bd196ae734d86da4eff
    SHA512 E4AEC26509F2C6820A69839CB8033BF27DDE6F02BE670FB212B1AADC6D167A0ADE771407508E20AD70D1277B687636093308846085C262FB938668724AC6C0B3
    HEAD_REF master
)

vcpkg_find_acquire_program(BISON)
vcpkg_find_acquire_program(FLEX)

get_filename_component(BISON_DIR "${BISON}" DIRECTORY)
get_filename_component(FLEX_DIR "${FLEX}" DIRECTORY)
vcpkg_add_to_path("${BISON_DIR}")
vcpkg_add_to_path("${FLEX_DIR}")

# Tool-only port: allow empty include folders.
set(VCPKG_POLICY_EMPTY_INCLUDE_FOLDER enabled)

# Tool-only port: build only CLI tools (no linkable libraries).
set(MATIEC_BUILD_SHARED OFF)
set(MATIEC_BUILD_STATIC OFF)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        "-DBISON_EXECUTABLE=${BISON}"
        "-DFLEX_EXECUTABLE=${FLEX}"
        "-DMATIEC_BUILD_TESTS=OFF"
        "-DMATIEC_BUILD_TOOLS=ON"
        "-DMATIEC_BUILD_SHARED=${MATIEC_BUILD_SHARED}"
        "-DMATIEC_BUILD_STATIC=${MATIEC_BUILD_STATIC}"
)

vcpkg_cmake_build()

vcpkg_cmake_install()

# Remove duplicate debug artifacts to satisfy vcpkg post-build checks.
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")
# Tool-only port: remove headers to avoid implying a linkable library.
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/include")

# Copy executables to tools directory
vcpkg_copy_tools(
    TOOL_NAMES iec2c iec2iec
    AUTO_CLEAN
)

# Install the IEC standard library files
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/share/${PORT}/lib")
file(INSTALL "${SOURCE_PATH}/src/lib/"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}/iec-lib"
    FILES_MATCHING
    PATTERN "*.txt"
    PATTERN "*.h"
)

# Create a usage file
file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/usage" [[
matiec provides the iec2c and iec2iec command-line tools.
This port installs tools only (no linkable libraries).

The tools are installed to: ${CURRENT_INSTALLED_DIR}/tools/matiec/

IEC standard library files are installed to:
  ${CURRENT_INSTALLED_DIR}/share/matiec/iec-lib/

Example CMake usage:
  find_program(IEC2C_EXECUTABLE iec2c HINTS "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/tools/matiec")
  set(MATIEC_LIB_DIR "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/matiec/iec-lib")

  add_custom_command(
      OUTPUT ${CMAKE_BINARY_DIR}/generated/program.c
      COMMAND ${IEC2C_EXECUTABLE} -I ${MATIEC_LIB_DIR} -T ${CMAKE_BINARY_DIR}/generated ${CMAKE_SOURCE_DIR}/program.st
      DEPENDS ${CMAKE_SOURCE_DIR}/program.st
  )
]])

# Remove empty directories to satisfy vcpkg post-build checks.
file(GLOB_RECURSE MATIEC_EMPTY_DIRS LIST_DIRECTORIES true "${CURRENT_PACKAGES_DIR}/*")
list(SORT MATIEC_EMPTY_DIRS DESCENDING)
foreach(MATIEC_EMPTY_DIR IN LISTS MATIEC_EMPTY_DIRS)
    if(IS_DIRECTORY "${MATIEC_EMPTY_DIR}")
        file(GLOB MATIEC_EMPTY_DIR_ENTRIES "${MATIEC_EMPTY_DIR}/*")
        list(LENGTH MATIEC_EMPTY_DIR_ENTRIES MATIEC_EMPTY_DIR_ENTRIES_LEN)
        if(MATIEC_EMPTY_DIR_ENTRIES_LEN EQUAL 0)
            file(REMOVE_RECURSE "${MATIEC_EMPTY_DIR}")
        endif()
    endif()
endforeach()

vcpkg_install_copyright(FILE_LIST
    "${SOURCE_PATH}/COPYING"
    "${SOURCE_PATH}/src/lib/COPYING.LESSER"
)
