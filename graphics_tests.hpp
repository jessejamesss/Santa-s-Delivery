#ifndef __GRAPHICS_TESTS_HPP__
#define __GRAPHICS_TESTS_HPP__

#include "gtest/gtest.h"
#include "Graphics.h"
#include "GraphicsComposite.h"
#include "MainBoard.h"
#include "AttemptsBoard.h"
#include "Text.h"
#include "Points.h"
#include "Attempts.h"

int** createGrid() {
   int** grid = new int*[6];
   int val = 0;
   for (int i = 0; i < 6; ++i) {
      grid[i] = new int[6];
      for (int j = 0; j < 6; ++j) {
         ++val;
         grid[i][j] = -1;
      }
   }
   return grid;
}

TEST(TextTests, WonderLandThemeTest) {
   Graphics* themeText = new Text(1,"Jesse");

   testing::internal::CaptureStdout();
   themeText->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, " Jesse's Winter Wonderland Board");
}

TEST(TextTests, NightmareThemeTest) {
   Graphics* themeText = new Text(2, "Jesse");
   
   testing::internal::CaptureStdout();
   themeText->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, " Jesse's Nightmare Before Christmas Board");
}

TEST(TextTests, AttemptsTextTest) {
   Graphics* attemptsText = new Text(0, "Jesse");
   
   testing::internal::CaptureStdout();
   attemptsText->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "      Attempts Board");
}

TEST(PointsTest, PointsOutputTest) {
   Graphics* points = new Points(0);

   testing::internal::CaptureStdout();
   points->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "Points: 0\n\n");
}

TEST(PointsTest, UpdatePointsTest) {
   Graphics* points = new Points(0);
   
   points->updatePoints(1);
   testing::internal::CaptureStdout();
   points->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "Points: 1\n\n");

   points->updatePoints(2);
   testing::internal::CaptureStdout();
   points->drawBoard();
   std::string output2 = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output2, "Points: 2\n\n");

   points->updatePoints(123456789);
   testing::internal::CaptureStdout();
   points->drawBoard();
   std::string output3 = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output3, "Points: 123456789\n\n");
}

TEST(AttemptsTest, AttemptsOutputTest) {
   Graphics* attempts = new Attempts();

   testing::internal::CaptureStdout();
   attempts->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "Attempts left: 1");
}

TEST(AttemptsTest, UpdateAttemptsTest) {
   Graphics* attempts = new Attempts();

   attempts->updateAttempts(3);
   testing::internal::CaptureStdout();
   attempts->drawBoard();
   std::string output = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output, "Attempts left: 3");

   attempts->updateAttempts(100);
   testing::internal::CaptureStdout();
   attempts->drawBoard();
   std::string output2 = testing::internal::GetCapturedStdout();
   EXPECT_EQ(output2, "Attempts left: 100");
}


TEST(MainBoardTest, MainBoardOutputTest) {
   Graphics* mainBoard = new MainBoard();

   testing::internal::CaptureStdout();
   mainBoard->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();
   
   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [ ] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [ ] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [ ] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [ ] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [ ] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [ ] \n");
}

TEST(MainBoardTest, UpdateMainBoardTest) {
   Graphics* mainBoard = new MainBoard();
   int** grid = createGrid();
   grid[0][0] = 40;
   grid[1][1] = 5;
   grid[2][2] = 50;
   grid[3][3] = 3;
   grid[4][4] = 60;
   grid[5][5] = 3;

   mainBoard->updateBoard(grid);
   testing::internal::CaptureStdout();
   mainBoard->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();
  
   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [\xE2\x98\x84] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [\xE2\x98\x86] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [\xE2\x98\x84] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [\xE2\x98\x86] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [\xE2\x98\x84] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [\xE2\x98\x86] \n");
}
   
TEST(AttemptsBoardTest, AttemptsBoardOutputTest) {
   Graphics* attemptsBoard = new AttemptsBoard();
   
   testing::internal::CaptureStdout();
   attemptsBoard->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [ ] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [ ] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [ ] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [ ] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [ ] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [ ] \n");
}

TEST(AttemptsBoardTest, UpdateAttemptsBoardTest) {
   Graphics* attemptsBoard = new AttemptsBoard();
   int** grid = createGrid();
   grid[0][0] = -2;
   grid[1][1] = -3;
   grid[2][2] = -2;
   grid[3][3] = -10;
   grid[4][4] = -2;
   grid[5][5] = -3;

   attemptsBoard->updateBoard(grid);
   testing::internal::CaptureStdout();
   attemptsBoard->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [\xC2\xB7] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [\xE2\x98\x86] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [\xC2\xB7] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [\xE2\x98\x84] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [\xC2\xB7] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [\xE2\x98\x86] \n");
}

TEST(GraphicsCompositeTest, DrawTextTest) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* themeText = new Text(0, "");

   board->add(themeText);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "      Attempts Board\n");
}

TEST(GraphicsCompositeTest, DrawTextTest2) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* themeText = new Text(1, "Jesse");

   board->add(themeText);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, " Jesse's Winter Wonderland Board\n");
}

TEST(GraphicsCompositeTest, DrawTextTest3) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* themeText = new Text(2, "Jesse");

   board->add(themeText);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, " Jesse's Nightmare Before Christmas Board\n");
}

TEST(GraphicsCompositeTest, DrawPointsTest) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* points = new Points(0);

   board->add(points);
   points->updatePoints(100);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "Points: 100\n\n\n");
}

TEST(GraphicsCompositeTest, DrawAttemptsTest) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* attempts = new Attempts();
   
   board->add(attempts);
   attempts->updateAttempts(3);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "Attempts left: 3\n");
}

TEST(GraphicsCompositeTest, DrawMainBoardTest) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* mainBoard = new MainBoard();
   int** grid = createGrid();
   grid[0][0] = 40;
   grid[1][1] = 5;
   grid[2][2] = 50;
   grid[3][3] = 3;
   grid[4][4] = 60;
   grid[5][5] = 70;

   board->add(mainBoard);
   mainBoard->updateBoard(grid);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [\xE2\x98\x84] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [\xE2\x98\x86] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [\xE2\x98\x84] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [\xE2\x98\x86] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [\xE2\x98\x84] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [\xE2\x98\x84] \n\n");
}

TEST(GraphicsCompositeTest, DrawAttemptsBoardTest) {
   GraphicsComposite* board = new GraphicsComposite();
   Graphics* attemptsBoard = new AttemptsBoard();
   int** grid = createGrid();
   grid[0][0] = -10;
   grid[1][1] = -3;
   grid[2][2] = -2;
   grid[3][3] = -10;
   grid[4][4] = -2;
   grid[5][5] = -3;

   board->add(attemptsBoard);
   attemptsBoard->updateBoard(grid);
   testing::internal::CaptureStdout();
   board->drawBoard();
   std:: string output = testing::internal::GetCapturedStdout();

   EXPECT_EQ(output, "              0   1   2   3   4   5\n           A [\xE2\x98\x84] [ ] [ ] [ ] [ ] [ ] \n           B [ ] [\xE2\x98\x86] [ ] [ ] [ ] [ ] \n           C [ ] [ ] [\xC2\xB7] [ ] [ ] [ ] \n           D [ ] [ ] [ ] [\xE2\x98\x84] [ ] [ ] \n           E [ ] [ ] [ ] [ ] [\xC2\xB7] [ ] \n           F [ ] [ ] [ ] [ ] [ ] [\xE2\x98\x86] \n\n");
}












#endif //__GRAPHICS_TESTS_HPP__ 
