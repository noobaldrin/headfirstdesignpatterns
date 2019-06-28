project("Simple Factory")

set(SRC main.cpp
	PizzaStore.cpp
	SimplePizzaFactory.cpp )

add_executable(pizza ${SRC})
