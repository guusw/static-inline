project(cpp_sandbox)

add_subdirectory(Catch2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(main_broken main_broken.cpp)
target_compile_features(main_broken PUBLIC cxx_std_20)
target_link_libraries(main_broken Catch2WithMain)

add_executable(main_ok main_ok.cpp)
target_compile_features(main_ok PUBLIC cxx_std_20)
target_link_libraries(main_ok Catch2WithMain)