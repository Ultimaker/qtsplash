set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -Werror -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")

set(QTSPLASH_SOURCES
	qtsplash.cpp
)

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Gui Qml Quick REQUIRED)
add_executable(qtsplash ${QTSPLASH_SOURCES})
add_definitions(${Qt5Gui_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Gui_EXECUTABLE_COMPILE_FLAGS} ${QtQml_EXECUTABLE_COMPILE_FLAGS} ${Qt5Quick_EXECUTABLE_COMPILE_FLAGS}")
target_include_directories(qtsplash PUBLIC
	${Qt5Gui_INCLUDE_DIRS}
	${QtQml_INCLUDE_DIRS}
	${Qt5Quick_INCLUDE_DIRS}
)
target_link_libraries(qtsplash PUBLIC
	${CMAKE_THREAD_LIBS_INIT}
	Qt5::Gui
	Qt5::Qml
	Qt5::Quick
)

install(
	PROGRAMS "${CMAKE_CURRENT_BINARY_DIR}/qtsplash"
	DESTINATION "${CMAKE_INSTALL_FULL_BINDIR}"
)
