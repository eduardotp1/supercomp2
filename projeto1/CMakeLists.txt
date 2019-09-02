cmake_minimum_required(VERSION 3.9)
project (projeto1)

add_executable(main_O3 main.cpp collision.cpp rect.cpp)
target_compile_definitions(main_O3 PUBLIC O3)

add_executable(main_fast main.cpp collision.cpp rect.cpp)
target_compile_definitions(main_fast PUBLIC S c O3 ftree-vectorize mavx )