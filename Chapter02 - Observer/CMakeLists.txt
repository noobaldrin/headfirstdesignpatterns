project(Observer)

set(SRC main.cpp
	    Subject.cpp
		Observer.cpp
		DisplayElement.cpp )

add_executable(weatherstation ${SRC})
