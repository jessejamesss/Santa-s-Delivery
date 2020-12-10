CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
	main.cpp
	Nightmare.cpp
	Wonderland.cpp
	GameOver.cpp
	SkipTurn.cpp
	MainBoard.cpp 
        GraphicsComposite.cpp
        AttemptsBoard.cpp
	Points.cpp
	Text.cpp
	AutoWin.cpp
	Attempts.cpp

)

ADD_EXECUTABLE(test
	test.cpp 
	Nightmare.cpp
        Wonderland.cpp
        GameOver.cpp
        SkipTurn.cpp
        MainBoard.cpp 
        GraphicsComposite.cpp
        AttemptsBoard.cpp
        Points.cpp
        Text.cpp
        AutoWin.cpp
        Attempts.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
