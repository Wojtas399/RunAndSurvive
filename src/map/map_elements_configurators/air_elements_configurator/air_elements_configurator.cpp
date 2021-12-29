#include "air_elements_configurator.h"

void AirElementsConfigurator::set(
    sf::Sprite &ground1,
    sf::Sprite &ground2,
    sf::Sprite &doubleLevel,
    sf::Sprite &doubleLevelReversed
) {
  std::vector<MapElement> elementsConfiguration;
  //configuration 1
  ground2.setPosition(288 + constants::windowWidth, 486);
  MapElement config1Ground2_1(MapElementType::airGround2, ground2);
  ground1.setPosition(544 + constants::windowWidth, 438);
  MapElement config1Ground1_1(MapElementType::airGround1, ground1);
  doubleLevel.setPosition(704 + constants::windowWidth, 358);
  MapElement config1DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevelReversed.setPosition(992 + constants::windowWidth, 358);
  MapElement config1DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config1Ground2_1,
      config1Ground1_1,
      config1DoubleLevel1,
      config1DoubleLevelReversed1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 2
  ground1.setPosition(544 + constants::windowWidth, 438);
  MapElement config2Ground1_1(MapElementType::airGround1, ground1);
  doubleLevel.setPosition(704 + constants::windowWidth, 358);
  MapElement config2DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  ground2.setPosition(1088 + constants::windowWidth, 358);
  MapElement config2Ground2_1(MapElementType::airGround2, ground2);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config2Ground1_1,
      config2DoubleLevel1,
      config2Ground2_1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 3
  doubleLevel.setPosition(416 + constants::windowWidth, 422);
  MapElement config3DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  ground2.setPosition(800 + constants::windowWidth, 422);
  MapElement config3Ground2_1(MapElementType::airGround2, ground2);
  ground2.setPosition(1056 + constants::windowWidth, 358);
  MapElement config3Ground2_2(MapElementType::airGround2, ground2);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config3DoubleLevel1,
      config3Ground2_1,
      config3Ground2_2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 4
  ground2.setPosition(96 + constants::windowWidth, 534);
  MapElement config4Ground2_1(MapElementType::airGround2, ground2);
  doubleLevel.setPosition(352 + constants::windowWidth, 400);
  MapElement config4DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  doubleLevel.setPosition(736 + constants::windowWidth, 272);
  MapElement config4DoubleLevel2(MapElementType::airDoubleLevel, doubleLevel);
  ground2.setPosition(1120 + constants::windowWidth, 272);
  MapElement config4Ground2_2(MapElementType::airGround2, ground2);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config4Ground2_1,
      config4DoubleLevel1,
      config4DoubleLevel2,
      config4Ground2_2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 5
  ground2.setPosition(576 + constants::windowWidth, 490);
  MapElement config5Ground2_1(MapElementType::airGround2, ground2);
  doubleLevel.setPosition(832 + constants::windowWidth, 362);
  MapElement config5DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  ground2.setPosition(1216 + constants::windowWidth, 298);
  MapElement config5Ground2_2(MapElementType::airGround2, ground2);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config5Ground2_1,
      config5DoubleLevel1,
      config5Ground2_2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 6
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 7
  doubleLevel.setPosition(320 + constants::windowWidth, 454);
  MapElement config7DoubleLevel1(MapElementType::airDoubleLevel, doubleLevel);
  ground1.setPosition(608 + constants::windowWidth, 454);
  MapElement config7Ground1_1(MapElementType::airGround1, ground1);
  ground1.setPosition(768 + constants::windowWidth, 454);
  MapElement config7Ground1_2(MapElementType::airGround1, ground1);
  ground1.setPosition(928 + constants::windowWidth, 454);
  MapElement config7Ground1_3(MapElementType::airGround1, ground1);
  ground2.setPosition(640 + constants::windowWidth, 374);
  MapElement config7Ground2_1(MapElementType::airGround2, ground2);
  ground2.setPosition(896 + constants::windowWidth, 374);
  MapElement config7Ground2_2(MapElementType::airGround2, ground2);
  doubleLevelReversed.setPosition(1088 + constants::windowWidth, 454);
  MapElement config7DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config7DoubleLevel1,
      config7Ground1_1,
      config7Ground1_2,
      config7Ground1_3,
      config7Ground2_1,
      config7Ground2_2,
      config7DoubleLevelReversed1,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
  //configuration 8
  ground2.setPosition(512 + constants::windowWidth, 470);
  MapElement config8Ground2_1(MapElementType::airGround2, ground2);
  ground1.setPosition(768 + constants::windowWidth, 390);
  MapElement config8Ground1_1(MapElementType::airGround1, ground1);
  doubleLevelReversed.setPosition(928 + constants::windowWidth, 390);
  MapElement config8DoubleLevelReversed1(MapElementType::airDoubleLevelReversed, doubleLevelReversed);
  ground2.setPosition(1184 + constants::windowWidth, 326);
  MapElement config8Ground2_2(MapElementType::airGround2, ground2);
  elementsConfiguration.insert(elementsConfiguration.end(), {
      config8Ground2_1,
      config8Ground1_1,
      config8DoubleLevelReversed1,
      config8Ground2_2,
  });
  configurations.push_back(elementsConfiguration);
  elementsConfiguration.clear();
}
