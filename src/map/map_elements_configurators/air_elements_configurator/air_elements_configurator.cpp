#include "air_elements_configurator.h"

void AirElementsConfigurator::set(
    sf::Sprite &simpleGround,
    sf::Sprite &doubleLevel,
    sf::Sprite &doubleLevelReversed
) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  simpleGround.setPosition(1688, 386);
  MapElement config1Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(1944, 322);
  MapElement config1Ground2(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(2104, 258);
  MapElement config1DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevelReversed.setPosition(2392, 258);
  MapElement config1DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config1Ground1,
      config1Ground2,
      config1DoubleLevel1,
      config1DoubleLevelReversed1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 2
  simpleGround.setPosition(1944, 322);
  MapElement config2Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(2104, 258);
  MapElement config2DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(2488, 258);
  MapElement config2Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Ground1,
      config2DoubleLevel1,
      config2Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  doubleLevel.setPosition(1816, 322);
  MapElement config3DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(2200, 322);
  MapElement config3Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(2456, 258);
  MapElement config3Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config3DoubleLevel1,
      config3Ground1,
      config3Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 4
  simpleGround.setPosition(1496, 428);
  MapElement config4Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(1752, 300);
  MapElement config4DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevel.setPosition(2136, 172);
  MapElement config4DoubleLevel2(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(2520, 172);
  MapElement config4Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config4Ground1,
      config4DoubleLevel1,
      config4DoubleLevel2,
      config4Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 5
  simpleGround.setPosition(1976, 390);
  MapElement config5Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(2232, 262);
  MapElement config5DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(2616, 198);
  MapElement config5Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config5Ground1,
      config5DoubleLevel1,
      config5Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 6
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
}
