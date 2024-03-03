file(GLOB_RECURSE
    SRC
    inc/Matrix.hpp
    inc/Vector.hpp
)

add_library(lib INTERFACE)
target_include_directories(lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
