project(arithmetic)

add_subdirectory(src)
add_subdirectory(test)

add_executable(arithmetic main.cpp)

target_link_libraries(arithmetic biginteger)