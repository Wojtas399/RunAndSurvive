#include "ground_elements_configurator.h"

void GroundElementsConfigurator::set(sf::Sprite simpleBlock, sf::Sprite stairs, sf::Sprite simpleWall) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  simpleBlock.setPosition(1464, 450);
  MapElement config1Block1(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2008, 450);
  MapElement config1Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(2328, 450);
  MapElement config1Block2(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2712, 450);
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
  stairs.setPosition(1464, 322);
  MapElement config2Stairs1(MapElementType::groundStairs, stairs);
  simpleBlock.setPosition(2104, 450);
  MapElement config2Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(2488, 450);
  MapElement config2Block2(MapElementType::groundBlock, simpleBlock);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Stairs1,
      config2Block1,
      config2Block2
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  simpleBlock.setPosition(1464, 450);
  MapElement config3Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(1592, 450);
  MapElement config3Block2(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2072, 450);
  MapElement config3Wall1(MapElementType::groundWall, simpleWall);
  simpleWall.setPosition(2328, 450);
  MapElement config3Wall2(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(2584, 450);
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
  stairs.setPosition(2168, 322);
  MapElement config4Stairs1(MapElementType::groundStairs, stairs);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config4Stairs1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 5
  simpleWall.setPosition(1528, 450);
  MapElement config5Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(1752, 450);
  MapElement config5Block1(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2424, 450);
  MapElement config5Wall2(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(2648, 450);
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
  simpleBlock.setPosition(1496, 450);
  MapElement config6Block1(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(1752, 450);
  MapElement config6Block2(MapElementType::groundBlock, simpleBlock);
  simpleBlock.setPosition(2008, 450);
  MapElement config6Block3(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2360, 450);
  MapElement config6Wall1(MapElementType::groundWall, simpleWall);
  simpleBlock.setPosition(2456, 450);
  MapElement config6Block4(MapElementType::groundBlock, simpleBlock);
  simpleWall.setPosition(2648, 450);
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
