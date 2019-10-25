project(DPGUI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GUI_SRC	DPGUI.cpp
		"../Chapter01 - Strategy/Duck.cpp" 
		"../Chapter01 - Strategy/QuackBehavior.cpp" 
		"../Chapter01 - Strategy/FlyBehavior.cpp" )

set(INCLUDE_DIRS "../Chapter01\ -\ Strategy")
include_directories(${INCLUDE_DIRS})

find_package(wxWidgets COMPONENTS core base REQUIRED)
if (wxWidgets_FOUND)
	include(${wxWidgets_USE_FILE} )
	add_executable(DPGUI ${GUI_SRC})
	target_link_libraries(DPGUI ${wxWidgets_LIBRARIES} )
endif()

