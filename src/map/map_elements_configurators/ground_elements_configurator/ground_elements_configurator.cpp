#include "ground_elements_configurator.h"

void GroundElementsConfigurator::set(sf::Sprite simpleBlock, sf::Sprite stairs, sf::Sprite simpleWall) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  simpleBlock.setPosition(64 + constants::windowWidth, 450);
  MapElement config1Block1(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(608 + constants::windowWidth, 450);
  MapElement config1Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(928 + constants::windowWidth, 450);
  MapElement config1Block2(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(1312 + constants::windowWidth, 450);
  MapElement config1Wall2(MapElementType::groundWall, simpleWall);
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
  simpleBlock.setPosition(704 + constants::windowWidth, 450);
  MapElement config2Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(1088 + constants::windowWidth, 450);
  MapElement config2Block2(MapElementType::groundBlock, simpleBlock);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Stairs1,
      config2Block1,
      config2Block2
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  simpleBlock.setPosition(64 + constants::windowWidth, 450);
  MapElement config3Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(192 + constants::windowWidth, 450);
  MapElement config3Block2(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(672 + constants::windowWidth, 450);
  MapElement config3Wall1(MapElementType::groundWall, simpleWall);
  simpleWall.setPosition(928 + constants::windowWidth, 450);
  MapElement config3Wall2(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(1184 + constants::windowWidth, 450);
  MapElement config3Block3(MapElementType::groundBlock, simpleBlock);
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
  simpleWall.setPosition(128 + constants::windowWidth, 450);
  MapElement config5Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(352 + constants::windowWidth, 450);
  MapElement config5Block1(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(1024 + constants::windowWidth, 450);
  MapElement config5Wall2(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(1248 + constants::windowWidth, 450);
  MapElement config5Block2(MapElementType::groundBlock, simpleBlock);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config5Wall1,
      config5Block1,
      config5Wall2,
      config5Block2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 6
  simpleBlock.setPosition(96 + constants::windowWidth, 450);
  MapElement config6Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(352 + constants::windowWidth, 450);
  MapElement config6Block2(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(608 + constants::windowWidth, 450);
  MapElement config6Block3(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(960 + constants::windowWidth, 450);
  MapElement config6Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(1056 + constants::windowWidth, 450);
  MapElement config6Block4(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(1248 + constants::windowWidth, 450);
  MapElement config6Wall2(MapElementType::groundWall, simpleWall);
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
}
