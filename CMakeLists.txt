cmake_minimum_required(VERSION 3.14)
project(SpaceShips)

set(CXX_STANDARD_REQUIRED 20)

set(FLAGS -Werror -Wall -Wpedantic -Wextra)

find_package(GTest REQUIRED)

set(SFML_LIB    sfml-graphics
                sfml-window
                sfml-system)

set(SRC         Source/Sprite.cpp
                Source/Moveable.cpp
                Source/Controllable.cpp
                Source/Bullet.cpp
                Source/Spaceship.cpp)

add_library(${PROJECT_NAME}-lib STATIC  ${SRC})

add_executable(${PROJECT_NAME}  main.cpp)
add_executable(TESTRUNNER   testRunner.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE   ${SFML_LIB}
                                                ${PROJECT_NAME}-lib)

target_link_libraries(TESTRUNNER PRIVATE ${GTEST_LIBRARIES}
                                         ${PROJECT_NAME}-lib
                                         ${SFML_LIB}
                                         pthread)


target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(TESTRUNNER   PRIVATE ${FLAGS})

set_target_properties(${PROJECT_NAME}-lib   PROPERTIES
                                            CXX_STANDARD 20
                                            CXX_STANDARD_REQUIRED ON)

set_target_properties(${PROJECT_NAME}   PROPERTIES
                                        CXX_STANDARD 20
                                        CXX_STANDARD_REQUIRED ON)

set_target_properties(TESTRUNNER    PROPERTIES
                                    CXX_STANDARD 20
                                    CXX_STANDARD_REQUIRED ON)

