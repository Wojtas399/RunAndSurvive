#include "air_elements_configurator.h"

void AirElementsConfigurator::set(
    sf::Sprite &simpleGround,
    sf::Sprite &doubleLevel,
    sf::Sprite &doubleLevelReversed
) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  simpleGround.setPosition(288 + constants::windowWidth, 386);
  MapElement config1Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(544 + constants::windowWidth, 322);
  MapElement config1Ground2(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(704 + constants::windowWidth, 258);
  MapElement config1DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevelReversed.setPosition(992 + constants::windowWidth, 258);
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
  simpleGround.setPosition(544 + constants::windowWidth, 322);
  MapElement config2Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(704 + constants::windowWidth, 258);
  MapElement config2DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(1088 + constants::windowWidth, 258);
  MapElement config2Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Ground1,
      config2DoubleLevel1,
      config2Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  doubleLevel.setPosition(416 + constants::windowWidth, 322);
  MapElement config3DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(800 + constants::windowWidth, 322);
  MapElement config3Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(1056 + constants::windowWidth, 258);
  MapElement config3Ground2(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config3DoubleLevel1,
      config3Ground1,
      config3Ground2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 4
  simpleGround.setPosition(96 + constants::windowWidth, 418);
  MapElement config4Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(352 + constants::windowWidth, 300);
  MapElement config4DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevel.setPosition(736 + constants::windowWidth, 172);
  MapElement config4DoubleLevel2(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(1120 + constants::windowWidth, 172);
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
  simpleGround.setPosition(576 + constants::windowWidth, 390);
  MapElement config5Ground1(MapElementType::airGround, simpleGround);
  doubleLevel.setPosition(832 + constants::windowWidth, 262);
  MapElement config5DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(1216 + constants::windowWidth, 198);
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
  //configuration 7
  doubleLevel.setPosition(320 + constants::windowWidth, 354);
  MapElement config7DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  simpleGround.setPosition(608 + constants::windowWidth, 354);
  MapElement config7Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(768 + constants::windowWidth, 354);
  MapElement config7Ground2(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(928 + constants::windowWidth, 354);
  MapElement config7Ground3(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(640 + constants::windowWidth, 258);
  MapElement config7Ground4(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(896 + constants::windowWidth, 258);
  MapElement config7Ground5(MapElementType::airGround, simpleGround);
  doubleLevelReversed.setPosition(1088 + constants::windowWidth, 354);
  MapElement config7DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config7DoubleLevel1,
      config7Ground1,
      config7Ground2,
      config7Ground3,
      config7Ground4,
      config7Ground5,
      config7DoubleLevelReversed1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 8
  simpleGround.setPosition(512 + constants::windowWidth, 354);
  MapElement config8Ground1(MapElementType::airGround, simpleGround);
  simpleGround.setPosition(768 + constants::windowWidth, 290);
  MapElement config8Ground2(MapElementType::airGround, simpleGround);
  doubleLevelReversed.setPosition(928 + constants::windowWidth, 290);
  MapElement config8DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  simpleGround.setPosition(1184 + constants::windowWidth, 226);
  MapElement config8Ground3(MapElementType::airGround, simpleGround);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config8Ground1,
      config8Ground2,
      config8DoubleLevelReversed1,
      config8Ground3,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
}
