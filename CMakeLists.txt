CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
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


