cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("Chapter01 - Strategy")
add_subdirectory("Chapter02 - Observer")
add_subdirectory("Chapter03 - Decorator")
add_subdirectory("Chapter04 - Factory")

option(GUI "Compile gui demos" OFF)

if (GUI)
	add_subdirectory("gui")
endif()
