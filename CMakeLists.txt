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
include_directories(${CMAKE_SOURCE_DIR}/extincludes/)

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

find_library( SFML_GRAPHICS    libsfml-graphics.so.2.4.1     ${SFML_LIBRARIES_DIR} )
find_library( SFML_SYSTEM      libsfml-system.so.2.4.1       ${SFML_LIBRARIES_DIR} )
find_library( SFML_WINDOW      libsfml-window.so.2.4.1       ${SFML_LIBRARIES_DIR} )
find_library( TGUI             libtgui.so.0.7.4              ${TGUI_LIBRARIES_DIR} )
find_library( BOOST_SYSTEM     libboost_system.so.1.63.0     ${BOOST_LIBRARIES_DIR} )
find_library( BOOST_FILESYSTEM libboost_filesystem.so.1.63.0 ${BOOST_LIBRARIES_DIR} )

message( "\nCheckings libraries ..." )
message( STATUS "   sfml_graphics: " ${SFML_GRAPHICS} )
message( STATUS "     sfml_system: " ${SFML_SYSTEM} )
message( STATUS "     sfml_window: " ${SFML_WINDOW} )   
message( STATUS "            tgui: " ${TGUI} )
message( STATUS "boost_filesystem: " ${BOOST_FILESYSTEM} )
message( STATUS "    boost_system: " ${BOOST_SYSTEM} )
message( "" )

set( CMAKE_CXX_FLAGS "-std=c++14 -Wall" )

add_executable( run ${SOURCES} )

target_link_libraries( run ${SFML_GRAPHICS}
                           ${SFML_SYSTEM}
                           ${SFML_WINDOW}
                           ${TGUI}
                           ${BOOST_FILESYSTEM}
                           ${BOOST_SYSTEM} )
			  
