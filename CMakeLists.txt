cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DELPP_NO_DEFAULT_LOG_FILE -DELPP_NO_LOG_TO_FILE")

project(zombie_game)

include_directories(${zombie_game_SOURCE_DIR}/src/engine)

set(YAML_CPP_LIBRARY /usr/local/lib/libyaml-cpp.a)
set(SDL2_LIBRARY /usr/local/lib/libSDL2.so)
set(SDL2_IMAGE_LIBRARY /usr/local/lib/libSDL2_image.so)
set(SDL2_TTF_LIBRARY /usr/local/lib/libSDL2_ttf.so)

file(GLOB ASSETS_SRC "src/engine/assets/*.cpp")
file(GLOB ELEMENTS_SRC "src/engine/elements/*.cpp")
file(GLOB SYSTEMS_SRC "src/engine/systems/*.cpp")

add_executable(
    ${PROJECT_NAME}
    ${ASSETS_SRC}
    ${ELEMENTS_SRC}
    ${SYSTEMS_SRC}
    src/engine/Engine.cpp
    src/engine/AssetManager.cpp
    src/engine/screens/menu/MenuScreen.cpp
    src/engine/utils/easylogging++.cpp
    src/engine/utils/Config.cpp
    src/game/main.cpp
    src/game/screens/menu/MainMenu.cpp
)

INCLUDE(FindPkgConfig)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME} 
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${YAML_CPP_LIBRARY}
)
