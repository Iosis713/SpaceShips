cmake_minimum_required(VERSION 3.14)
project(SpaceShips)

set(CXX_STANDARD_REQUIRED 20)

set(FLAGS -Werror -Wall -Wpedantic -Wextra)

set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

set(SRC         Source/Sprite.cpp
                Source/Moveable.cpp)

add_library(${PROJECT_NAME}-lib STATIC  ${SRC})

add_executable(${PROJECT_NAME}  main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE   ${SFML_LIB}
                                                ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})


set_target_properties(${PROJECT_NAME}-lib   PROPERTIES
                                            CXX_STANDARD 20
                                            CXX_STANDARD_REQUIRED ON)

set_target_properties(${PROJECT_NAME}   PROPERTIES
                                        CXX_STANDARD 20
                                        CXX_STANDARD_REQUIRED ON)

