project(Strategy)

set(SRC main.cpp
	    Duck.cpp
		FlyBehavior.cpp
		QuackBehavior.cpp )

add_executable(duck ${SRC})
