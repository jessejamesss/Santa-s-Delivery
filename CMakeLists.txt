CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
   test.cpp
   AttemptsBoard.cpp
   MainBoard.cpp
   Text.cpp
   Points.cpp
   Attempts.cpp
   GraphicsComposite.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_diable_pthreads=ON)
