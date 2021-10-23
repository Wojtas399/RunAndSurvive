cmake_minimum_required(VERSION 3.20)
project(R_S)

set(CMAKE_CXX_STANDARD 14)

add_executable(R_S
        src/main.cpp
        src/map/generators/background/background_generator.cpp
        src/map/generators/map/map_generator.cpp
        src/map/generators/air_elements/air_elements_generator.cpp
        src/map/generators/ground_elements/ground_elements_generator.cpp
        src/models/map/map_element.cpp
        src/map/map_elements_configurators/air_elements_configurator/air_elements_configurator.cpp
        src/map/map_elements_configurators/ground_elements_configurator/ground_elements_configurator.cpp)

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
