cmake_minimum_required(VERSION 2.8)

project( QueenGame )

find_package(SFML REQUIRED)

set(SFML_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/lib/SFML)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/sources/)

file( GLOB SOURCES "${SOURCE_DIR}/Logic/*.cpp"
		   "${SOURCE_DIR}/Logic/*.hpp"
		   "${SOURCE_DIR}/Graphics/*.cpp"
		   "${SOURCE_DIR}/Graphics/*.hpp"
		   "${SOURCE_DIR}/ResourceManagment/*.cpp"
		   "${SOURCE_DIR}/ResourceManagment/*.hpp"
		   "${SOURCE_DIR}/*.hpp"
		   "${SOURCE_DIR}/*.cpp")

set( CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs -Wall" )

add_executable( run ${SOURCES} )

TARGET_LINK_LIBRARIES(run ${SFML_LIBRARIES_DIR}/libsfml-audio.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-graphics.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-system.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-window.so.2.4.1
			  ${SFML_LIBRARIES_DIR}/libsfml-network.so.2.4.1)
