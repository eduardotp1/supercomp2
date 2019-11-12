cmake_minimum_required(VERSION 3.0.0)
project(project3 LANGUAGES CXX CUDA)

include(CTest)
enable_testing()

find_package(OpenMP REQUIRED)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(tsp-seq
    tsp-seq.cpp
)
target_compile_options(tsp-seq PUBLIC -O3)

add_executable(tsp-seq-bb
    tsp-seq-bb.cpp
)
target_compile_options(tsp-seq-bb PUBLIC -O3)


add_executable(tsp-par
    tsp-par.cpp
)
target_compile_options(tsp-par PUBLIC -O3 -fopenmp)
target_link_libraries(tsp-par OpenMP::OpenMP_CXX)

add_executable(random-sol
    random-sol.cu
)
target_compile_options(random-sol PUBLIC -std=c++11 -O3 )

add_executable(2-opt-sol
    2-opt-sol.cu
)
target_compile_options(2opt-sol PUBLIC -std=c++11 -O3)
