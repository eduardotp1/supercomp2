cmake_minimum_required(VERSION 3.0.0)
project(collision_project VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(collision 
    rectangle.cpp
    collision.cpp
    main.cpp
)

add_executable(collision_O0 
    rectangle.cpp
    collision.cpp
    main.cpp
)
target_compile_options(collision_O0 PUBLIC -O0)

add_executable(collision_O1
    rectangle.cpp
    collision.cpp
    main.cpp
)
target_compile_options(collision_O0 PUBLIC -O1)

add_executable(collision_O3 
    rectangle.cpp
    collision.cpp
    main.cpp
)
target_compile_options(collision_O0 PUBLIC -O3)

add_executable(collision_O3_SIMD 
    rectangle.cpp
    collision.cpp
    main.cpp
)
target_compile_options(collision_O3_SIMD PUBLIC -O3 -mavx -ffast-math -ftree-vectorize)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)