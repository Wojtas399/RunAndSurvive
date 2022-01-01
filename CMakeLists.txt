cmake_minimum_required(VERSION 3.14)
project(R_S)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(R_S
        src/main.cpp
        src/map/generators/background/background_generator.cpp
        src/map/generators/map/map_generator.cpp
        src/map/generators/air_elements/air_elements_generator.cpp
        src/map/generators/ground_elements/ground_elements_generator.cpp
        src/models/map/map_element.cpp
        src/map/map_elements_configurators/air_elements_configurator/air_elements_configurator.cpp
        src/map/map_elements_configurators/ground_elements_configurator/ground_elements_configurator.cpp
        src/models/robot/robot.cpp
        src/robot/robot_controller.cpp
        src/robot/animations/robot_animations.cpp
        src/robot/movement_controller/robot_movement_controller.cpp
        src/object_collisions/robot/robot_collisions.cpp
        src/robot/movement/robot_movement.cpp
        src/robot/shoot_controller/robot_shoot_controller.cpp
        src/models/bullet/bullet.cpp
        src/robot/textures/robot_textures.cpp
        src/object_collisions/bullet/bullet_collisions.cpp
        src/object_collisions/map_elements/map_elements_collisions.cpp
        src/zombie/zombie_controller.cpp
        src/zombie/zombie_controller.h src/models/zombie/zombie.cpp
        src/zombie/textures/zombie_textures.cpp
        src/zombie/animations/zombie_animations.cpp
        src/zombie/movement/zombie_movement_controller.cpp
        src/object_collisions/zombie/zombie_collisions.cpp
        src/global_controller/global_controller.cpp
        src/object_collisions/robot_zombie/robot_zombie_collisions.cpp
        src/points_service/points_service.cpp
        src/life_service/life_service.cpp
        src/game_params/game_params.cpp
        src/ui_service/ui_service.cpp
        src/models/zombie_points/zombie_points.cpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(R_S sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
