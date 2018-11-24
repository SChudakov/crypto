project(alg)

add_executable(alg main.cpp)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(alg algorithm)
target_link_libraries(alg biginteger)
