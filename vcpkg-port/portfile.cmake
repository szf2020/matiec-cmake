# NOTE: This port requires flex and bison to be installed on the system
# Windows: choco install winflexbison3
# macOS: brew install flex bison
# Linux: apt install flex bison

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO lusipad/matiec-cmake
    REF master                   # Replace with version tag
    SHA512 0                     # Update with: vcpkg hash <archive-url>
    HEAD_REF master
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_build()

vcpkg_cmake_install()

# Copy executables to tools directory
vcpkg_copy_tools(
    TOOL_NAMES iec2c iec2iec
    AUTO_CLEAN
)

# Install the IEC standard library files
file(INSTALL "${SOURCE_PATH}/lib/"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}/lib"
    FILES_MATCHING
    PATTERN "*.txt"
    PATTERN "*.h"
)

# Create a usage file
file(WRITE "${CURRENT_PACKAGES_DIR}/share/${PORT}/usage" [[
matiec provides the iec2c and iec2iec command-line tools.

The tools are installed to: ${CURRENT_INSTALLED_DIR}/tools/matiec/

IEC standard library files are installed to:
  ${CURRENT_INSTALLED_DIR}/share/matiec/lib/

Example CMake usage:
  find_program(IEC2C_EXECUTABLE iec2c HINTS "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/tools/matiec")
  set(MATIEC_LIB_DIR "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/matiec/lib")

  add_custom_command(
      OUTPUT ${CMAKE_BINARY_DIR}/generated/program.c
      COMMAND ${IEC2C_EXECUTABLE} -I ${MATIEC_LIB_DIR} -T ${CMAKE_BINARY_DIR}/generated ${CMAKE_SOURCE_DIR}/program.st
      DEPENDS ${CMAKE_SOURCE_DIR}/program.st
  )
]])

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/COPYING")
