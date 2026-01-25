# stage4 - Code Generation

# Shared base object (stage4.cc is used by both generators)
add_library(stage4_base OBJECT stage4.cc)
target_include_directories(stage4_base PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}
)

# C code generator (iec2c)
add_library(stage4_c STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_c/generate_c.cc
)
target_include_directories(stage4_c PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generate_c
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(stage4_c PUBLIC absyntax)
target_link_libraries(stage4_c PUBLIC matiec_error)

# IEC code generator (iec2iec)
add_library(stage4_iec STATIC
    $<TARGET_OBJECTS:stage4_base>
    generate_iec/generate_iec.cc
)
target_include_directories(stage4_iec PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generate_iec
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(stage4_iec PUBLIC absyntax)
target_link_libraries(stage4_iec PUBLIC matiec_error)

# IEC code generator (for libmatiec runtime dispatch)
# - Compiles the IEC generator with renamed symbols to avoid collisions with the
#   C generator (both are linked into libmatiec).
# - Does NOT include stage4.cc; it relies on stage4_c's stage4.cc for stage4out_c
#   and common helpers.
add_library(stage4_iec_alt STATIC
    generate_iec/generate_iec.cc
)
target_compile_definitions(stage4_iec_alt PRIVATE
    new_code_generator=new_iec_code_generator
    delete_code_generator=delete_iec_code_generator
    stage4_parse_options=stage4_iec_parse_options
    stage4_print_options=stage4_iec_print_options
)
target_include_directories(stage4_iec_alt PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/generate_iec
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(stage4_iec_alt PUBLIC absyntax)
target_link_libraries(stage4_iec_alt PUBLIC matiec_error)
