#include "gtest/gtest.h"
#include <iostream>
#include "Neighborhood.h"
#include "Wonderland.h"
#include "Nightmare.h"
#include "GameOver.h"
#include "GameState.hpp"
#include "SkipTurn.h"


TEST(Wonderland, ConstructorCheckWonderland) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->getPoints(), 0);
    EXPECT_EQ(player->getTheme(), "Wonderland");
    EXPECT_EQ(player->getAttempts(), 1);
    EXPECT_EQ(player->getGameOver(), false);
    EXPECT_EQ(player->getBonusCoordinateX(), 0);
    EXPECT_EQ(player->getBonusCoordinateY(), 0);

}

TEST(Wonderland, CheckAttempts1) {
    Neighborhood* player = new Wonderland();
    player->setAttempts(0);
    EXPECT_EQ(player->getAttempts(), 0);
}


TEST(Wonderland, CheckAttempts2) {
    Neighborhood* player = new Wonderland();
    player->setAttempts(3);
    EXPECT_EQ(player->getAttempts(), 3);
}

TEST(Wonderland, CheckAttempts3) {
    Neighborhood* player = new Wonderland();
    player->setAttempts(10);
    EXPECT_EQ(player->getAttempts(), 10);
}

TEST(Wonderland, CheckAttempts4) {
    Neighborhood* player = new Wonderland();
    player->setAttempts(-1);
    EXPECT_EQ(player->getAttempts(), -1);
}

TEST(Wonderland, Theme) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->getTheme(), "Wonderland");
}

TEST(Wonderland, checkRow1) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkRow('a'),true);
}

TEST(Wonderland, checkRow2) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkRow('e'),true);
}

TEST(Wonderland, checkRow3) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkRow('z'),false);
}

TEST(Wonderland, checkRow4) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkRow('f'),true);
}

TEST(Wonderland, checkRow5) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkRow('g'),false);
}

TEST(Wonderland, checkCol1) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkCol('0'),true);
}

TEST(Wonderland, checkCol2) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkCol('4'),true);
}

TEST(Wonderland, checkCol3) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkCol('9'),false);
}

TEST(Wonderland, checkCol4) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkCol('5'),true);
}

TEST(Wonderland, checkCol5) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkCol('6'),false);
}

TEST(Wonderland, BonusCoordX) {
    Neighborhood* player = new Wonderland();
    player->setBonusCoordinateX('a');
    EXPECT_EQ(player->getBonusCoordinateX(), 97);
}

TEST(Wonderland, BonusCoordY) {
    Neighborhood* player = new Wonderland();
    player->setBonusCoordinateY(2);
    EXPECT_EQ(player->getBonusCoordinateY(), 2);
}

TEST(Wonderland, Valid1) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkValidity('a', 2), true);
}

TEST(Wonderland, Valid2) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkValidity('f', 0), true);
}

TEST(Wonderland, Valid3) {
    Neighborhood* player = new Wonderland();
    EXPECT_EQ(player->checkValidity('e', 5), true);
}


TEST(Nightmare, NConstructorCheckNightmare) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->getPoints(), 0);
    EXPECT_EQ(player->getTheme(), "Nightmare");
    EXPECT_EQ(player->getAttempts(), 1);
    EXPECT_EQ(player->getGameOver(), false); 
    EXPECT_EQ(player->getBonusCoordinateX(), 0);
    EXPECT_EQ(player->getBonusCoordinateY(), 0);

}

TEST(Nightmare, NCheckAttempts1) {
    Neighborhood* player = new Nightmare();
    player->setAttempts(0);
    EXPECT_EQ(player->getAttempts(), 0);
}


TEST(Nightmare, NCheckAttempts2) {
    Neighborhood* player = new Nightmare();
    player->setAttempts(3);
    EXPECT_EQ(player->getAttempts(), 3);
}

TEST(Nightmare, NCheckAttempts3) {
    Neighborhood* player = new Nightmare();
    player->setAttempts(10);
    EXPECT_EQ(player->getAttempts(), 10);
}

TEST(Nightmare, NCheckAttempts4) {
    Neighborhood* player = new Nightmare();
    player->setAttempts(-1);
    EXPECT_EQ(player->getAttempts(), -1);
}

TEST(Nightmare, NTheme) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->getTheme(), "Nightmare");
}

TEST(Nightmare, NcheckRow1) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkRow('a'),true);
}

TEST(Nightmare, NcheckRow2) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkRow('e'),true);
}

TEST(Nightmare, NcheckRow3) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkRow('z'),false);
}

TEST(Nightmare, NcheckRow4) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkRow('f'),true);
}

TEST(Nightmare, NcheckRow5) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkRow('g'),false);
}

TEST(Nightmare, NcheckCol1) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkCol('0'),true);
}

TEST(Nightmare, NcheckCol2) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkCol('4'),true);
}

TEST(Nightmare, NcheckCol3) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkCol('9'),false);
}

TEST(Nightmare, NcheckCol4) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkCol('5'),true);
}

TEST(Nightmare, NcheckCol5) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkCol('6'),false);
}
TEST(Nightmare, NBonusCoordX) {
    Neighborhood* player = new Nightmare();
    player->setBonusCoordinateX('a');
    EXPECT_EQ(player->getBonusCoordinateX(), 97);
}

TEST(Nightmare, NBonusCoordY) {
    Neighborhood* player = new Nightmare();
    player->setBonusCoordinateY(2);
    EXPECT_EQ(player->getBonusCoordinateY(), 2);
}

TEST(Nightmare, NValid1) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkValidity('a', 2), true);
}

TEST(Nightmare, NValid2) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkValidity('f', 0), true);
}

TEST(Nightmare, NValid3) {
    Neighborhood* player = new Nightmare();
    EXPECT_EQ(player->checkValidity('e', 5), true);
}







int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

