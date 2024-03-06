cmake_minimum_required(VERSION 3.14)
project(SpaceShips)

set(CXX_STANDARD_REQUIRED 20)

set(FLAGS -Werror -Wall -Wpedantic -Wextra)

set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

add_executable(${PROJECT_NAME}  main.cpp)

target_link_libraries(${PROJECT_NAME}   ${SFML_LIB})

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})

set_target_properties(${PROJECT_NAME}   PROPERTIES
                                        CXX_STANDARD 20
                                        CXX_STANDARD_REQUIRED ON)

