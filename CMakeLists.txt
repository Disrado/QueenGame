cmake_minimum_required(VERSION 2.8)

if ( NOT UNIX )
    message (FATAL_ERROR "Not Unix!")
endif ()

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project( QueenGame )

set(SFML_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/SFML/)
set(TGUI_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/TGUI/)
set(BOOST_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/BOOST/)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/sources/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

include_directories(${CMAKE_SOURCE_DIR}/extincludes/)
include_directories(${SFML_LIBRARIES_DIR})

file( GLOB SOURCES "${SOURCE_DIR}/include/SceneManagment/Scenes/*.hpp"
  "${SOURCE_DIR}/include/ResourceManagment/*.hpp"
  "${SOURCE_DIR}/include/SceneManagment/*.hpp"
  "${SOURCE_DIR}/include/PlayersSystem/*.hpp"
  "${SOURCE_DIR}/include/GameObjects/*.hpp"
  "${SOURCE_DIR}/include/GameSystem/*.hpp"
  "${SOURCE_DIR}/include/Logic/*.hpp"
  "${SOURCE_DIR}/src/SceneManagment/Scenes/*.cpp" 
  "${SOURCE_DIR}/src/ResourceManagment/*.cpp"
  "${SOURCE_DIR}/src/SceneManagment/*.cpp"
  "${SOURCE_DIR}/src/PlayersSystem/*.cpp"
  "${SOURCE_DIR}/src/GameObjects/*.cpp"
  "${SOURCE_DIR}/src/GameSystem/*.cpp"
  "${SOURCE_DIR}/src/Logic/*.cpp")

find_library( SFML_GRAPHICS sfml-graphics          ${SFML_LIBRARIES_DIR} )
find_library( SFML_SYSTEM sfml-system              ${SFML_LIBRARIES_DIR} )
find_library( SFML_WINDOW sfml-window              ${SFML_LIBRARIES_DIR} )
find_library( TGUI tgui                         ${TGUI_LIBRARIES_DIR} )
find_library( BOOST_SYSTEM boost_system         ${BOOST_LIBRARIES_DIR} )
find_library( BOOST_FILESYSTEM boost_filesystem ${BOOST_LIBRARIES_DIR} )

message( "\nCheckings libraries ..." )
message( STATUS "   sfml_graphics: " ${SFML_GRAPHICS} )
message( STATUS "     sfml_system: " ${SFML_SYSTEM} )
message( STATUS "     sfml_window: " ${SFML_WINDOW} )   
message( STATUS "            tgui: " ${TGUI} )
message( STATUS "boost_filesystem: " ${BOOST_FILESYSTEM} )
message( STATUS "    boost_system: " ${BOOST_SYSTEM} )
message( "" )

link_directories( ${SFML_LIBRARIES_DIR} )
link_directories( ${TGUI_LIBRARIES_DIR} )
link_directories( ${BOOST_LIBRARIES_DIR} ) 

message(${SFML_LIBRARIES_DIR})
message(${TGUI_LIBRARIES_DIR})

set( CMAKE_CXX_FLAGS "-std=c++14 -Wall" )

add_executable( run ${SOURCES} )

target_link_libraries( run sfml-system sfml-window sfml-graphics )
target_link_libraries( run tgui )
target_link_libraries( run boost_system boost_filesystem)

