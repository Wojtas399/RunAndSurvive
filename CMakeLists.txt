cmake_minimum_required(VERSION 3.20)
project(R_S)

set(CMAKE_CXX_STANDARD 14)

add_executable(R_S
        src/main.cpp
        src/background/background.cpp
        src/ground_generator/ground_generator.cpp
        src/ground_generator/ground_generator.h)

include_directories(C:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(R_S ${SFML_LIBRARIES})
endif ()

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
