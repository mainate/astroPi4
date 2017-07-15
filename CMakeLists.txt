cmake_minimum_required(VERSION 3.2)
set(CMAKE_C_COMPILER gcc)

project(astroPi4)


set(CMAKE_INSTALL_PREFIX /usr)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")

add_executable(
	astroPi4
	src/main.cpp
	include/astrocurses.h
	src/astrocurses.cpp
	src/configurationXML.cpp
	include/apiwebindimanager.h
	src/apiwebindimanager.cpp
	include/jsontools.h
	src/jsontools.cpp
	src/objbutton.cpp
	src/objwindow.cpp
	include/pipeopen.h
	src/pipeopen.cpp
	include/screensaver.h
	src/screensaver.cpp
	include/timerpthread.h
	src/timerpthread.cpp
)

link_directories(/usr/include/X11/)
target_link_libraries (astroPi4 X11)

link_directories(/usr/include/)
target_link_libraries (astroPi4 curl)

link_directories(/usr/include/)
target_link_libraries (astroPi4 ncurses)

link_directories(/usr/include/wx-3.0/wx/)
target_link_libraries (astroPi4 pthread)

link_directories(/usr/include/libevdev-1.0/)
target_link_libraries (astroPi4 evdev)

link_directories(/usr/include/)
target_link_libraries (astroPi4 tinyxml2)
	
link_directories(/usr/include/json-c/)
target_link_libraries (astroPi4 json)

link_directories(/usr/include/)
target_link_libraries (astroPi4 sqlite3)

install(TARGETS astroPi4 RUNTIME DESTINATION bin)
