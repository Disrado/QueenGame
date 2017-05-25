cmake_minimum_required(VERSION 2.8)

if (NOT UNIX)
    message (FATAL_ERROR "Not Unix!")
endif ()

project(QueenGame)

set(SFML_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/lib/SFML/)
set(TGUI_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/lib/TGUI/)
set(BOOST_LIBRARIES_DIR ${CMAKE_SOURCE_DIR}/extlibs/lib/BOOST/)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

#SGML-, TGUI-headers
include_directories(${CMAKE_SOURCE_DIR}/extlibs/include)

link_directories(${SFML_LIBRARIES_DIR})
link_directories(${TGUI_LIBRARIES_DIR})
link_directories(${BOOST_LIBRARIES_DIR}) 

file(GLOB HEADERS
  "${SOURCE_DIR}/include/GameObjects/*.hpp"
  "${SOURCE_DIR}/include/SceneManagment/Scenes/*.hpp"
  "${SOURCE_DIR}/include/SceneManagment/*.hpp"
  "${SOURCE_DIR}/include/Logic/*.hpp"
  "${SOURCE_DIR}/include/Logic/PlayersSystem/*.hpp"
  "${SOURCE_DIR}/include/GameSystem/*.hpp")

file(GLOB SOURCES
  "${SOURCE_DIR}/src/GameObjects/*.cpp"
  "${SOURCE_DIR}/src/SceneManagment/Scenes/*.cpp" 
  "${SOURCE_DIR}/src/SceneManagment/*.cpp"
  "${SOURCE_DIR}/src/Logic/*.cpp"
  "${SOURCE_DIR}/src/Logic/PlayersSystem/*.cpp"
  "${SOURCE_DIR}/src/GameSystem/*.cpp")

find_library(SFML_GRAPHICS    sfml-graphics    ${SFML_LIBRARIES_DIR})
find_library(SFML_SYSTEM      sfml-system      ${SFML_LIBRARIES_DIR})
find_library(SFML_WINDOW      sfml-window      ${SFML_LIBRARIES_DIR})
find_library(SFML_AUDIO      sfml-audio       ${SFML_LIBRARIES_DIR})
find_library(TGUI             tgui             ${TGUI_LIBRARIES_DIR})
find_library(BOOST_SYSTEM     boost_system     ${BOOST_LIBRARIES_DIR})
find_library(BOOST_FILESYSTEM boost_filesystem ${BOOST_LIBRARIES_DIR})

message("\nCheckings libraries ..." )
message(STATUS "   sfml_graphics: " ${SFML_GRAPHICS})
message(STATUS "     sfml_system: " ${SFML_SYSTEM})
message(STATUS "     sfml_window: " ${SFML_WINDOW})
message(STATUS "      sfml_audio: " ${SFML_AUDIO})   
message(STATUS "            tgui: " ${TGUI})
message(STATUS "boost_filesystem: " ${BOOST_FILESYSTEM})
message(STATUS "    boost_system: " ${BOOST_SYSTEM})
message("")

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(run ${SOURCES} ${HEADERS})

target_link_libraries(run
  sfml-system
  sfml-window
  sfml-graphics
  sfml-audio
  tgui
  boost_system
  boost_filesystem)
