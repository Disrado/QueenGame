cmake_minimum_required(VERSION 2.8)

project( QueenGame )

find_package(SFML REQUIRED)

set(SFML_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/lib/SFML)
set(TGUI_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/lib/TGUI)
set(BOOST_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/lib/Boost)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/sources/)


file( GLOB SOURCES "${SOURCE_DIR}/ResourceManagment/*.hpp"
		   "${SOURCE_DIR}/ResourceManagment/*.cpp"
                   "${SOURCE_DIR}/SceneManagment/*.hpp"
                   "${SOURCE_DIR}/SceneManagment/*.cpp"
		   "${SOURCE_DIR}/GameObjects/*.hpp"
		   "${SOURCE_DIR}/GameObjects/*.cpp"
                   "${SOURCE_DIR}/Scenes/*.hpp"    
		   "${SOURCE_DIR}/Scenes/*.cpp"
                   "${SOURCE_DIR}/Logic/*.hpp"
		   "${SOURCE_DIR}/Logic/*.cpp")                  

set( CMAKE_CXX_FLAGS "-std=c++17 -Wall" )

add_executable( run ${SOURCES} )

TARGET_LINK_LIBRARIES(run ${SFML_LIBRARIES_DIR}/libsfml-audio.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-graphics.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-system.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-window.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-network.so.2.4.1
                          ${TGUI_LIBRARIES_DIR}/libtgui.so.0.7.4
			  ${BOOST_LIBRARIES_DIR}/libboost_system.so.1.63.0
			  ${BOOST_LIBRARIES_DIR}/libboost_filesystem.so.1.63.0)
			  
