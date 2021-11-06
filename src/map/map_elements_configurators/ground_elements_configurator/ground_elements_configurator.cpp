#include "ground_elements_configurator.h"

void GroundElementsConfigurator::set(sf::Sprite block, sf::Sprite stairs, sf::Sprite wall) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  block.setPosition(64, 450);
  MapElement config1Block1(MapElementType::groundBlock, block);
  wall.setPosition(608, 457);
  MapElement config1Wall1(MapElementType::groundWall, wall);
  block.setPosition(928, 450);
  MapElement config1Block2(MapElementType::groundBlock, block);
  wall.setPosition(1312, 457);
  MapElement config1Wall2(MapElementType::groundWall, wall);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config1Block1,
      config1Wall1,
      config1Block2,
      config1Wall2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 2
  stairs.setPosition(64 + constants::windowWidth, 322);
  MapElement config2Stairs1(MapElementType::groundStairs, stairs);
  block.setPosition(704 + constants::windowWidth, 450);
  MapElement config2Block1(MapElementType::groundBlock, block);
  block.setPosition(1088 + constants::windowWidth, 450);
  MapElement config2Block2(MapElementType::groundBlock, block);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Stairs1,
      config2Block1,
      config2Block2
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  block.setPosition(64 + constants::windowWidth, 450);
  MapElement config3Block1(MapElementType::groundBlock, block);
  block.setPosition(192 + constants::windowWidth, 450);
  MapElement config3Block2(MapElementType::groundBlock, block);
  wall.setPosition(672 + constants::windowWidth, 457);
  MapElement config3Wall1(MapElementType::groundWall, wall);
  wall.setPosition(928 + constants::windowWidth, 457);
  MapElement config3Wall2(MapElementType::groundWall, wall);
  block.setPosition(1184 + constants::windowWidth, 450);
  MapElement config3Block3(MapElementType::groundBlock, block);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config3Block1,
      config3Block2,
      config3Wall1,
      config3Wall2,
      config3Block3,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 4
  stairs.setPosition(768 + constants::windowWidth, 322);
  MapElement config4Stairs1(MapElementType::groundStairs, stairs);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config4Stairs1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 5
  wall.setPosition(128 + constants::windowWidth, 457);
  MapElement config5Wall1(MapElementType::groundWall, wall);
  block.setPosition(352 + constants::windowWidth, 450);
  MapElement config5Block1(MapElementType::groundBlock, block);
  wall.setPosition(1024 + constants::windowWidth, 457);
  MapElement config5Wall2(MapElementType::groundWall, wall);
  block.setPosition(1248 + constants::windowWidth, 450);
  MapElement config5Block2(MapElementType::groundBlock, block);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config5Wall1,
      config5Block1,
      config5Wall2,
      config5Block2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 6
  block.setPosition(96 + constants::windowWidth, 450);
  MapElement config6Block1(MapElementType::groundBlock, block);
  block.setPosition(352 + constants::windowWidth, 450);
  MapElement config6Block2(MapElementType::groundBlock, block);
  block.setPosition(608 + constants::windowWidth, 450);
  MapElement config6Block3(MapElementType::groundBlock, block);
  wall.setPosition(960 + constants::windowWidth, 457);
  MapElement config6Wall1(MapElementType::groundWall, wall);
  block.setPosition(1056 + constants::windowWidth, 450);
  MapElement config6Block4(MapElementType::groundBlock, block);
  wall.setPosition(1248 + constants::windowWidth, 457);
  MapElement config6Wall2(MapElementType::groundWall, wall);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config6Block1,
      config6Block2,
      config6Block3,
      config6Wall1,
      config6Block4,
      config6Wall2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 7
  block.setPosition(96 + constants::windowWidth, 450);
  MapElement config7Block1(MapElementType::groundBlock, block);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config7Block1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 8
  block.setPosition(96 + constants::windowWidth, 450);
  MapElement config8Block1(MapElementType::groundBlock, block);
  block.setPosition(352 + constants::windowWidth, 450);
  MapElement config8Block2(MapElementType::groundBlock, block);
  block.setPosition(480 + constants::windowWidth, 450);
  MapElement config8Block3(MapElementType::groundBlock, block);
  block.setPosition(608 + constants::windowWidth, 450);
  MapElement config8Block4(MapElementType::groundBlock, block);
  wall.setPosition(928 + constants::windowWidth, 457);
  MapElement config8Wall1(MapElementType::groundWall, wall);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config8Block1,
      config8Block2,
      config8Block3,
      config8Block4,
      config8Wall1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
}
