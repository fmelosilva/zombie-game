cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DELPP_NO_DEFAULT_LOG_FILE -DELPP_NO_LOG_TO_FILE")

project(zombie-game)

set(YAML_CPP_LIBRARY /usr/local/lib/libyaml-cpp.a)
set(SDL2_LIBRARY /usr/local/lib/libSDL2-2.0.so.0)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/Config.cpp
    src/Game.cpp
    src/utils/easylogging++.cpp
    src/SDL2/Window.cpp
)

INCLUDE(FindPkgConfig)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME} 
    ${SDL2_LIBRARY} 
    ${YAML_CPP_LIBRARY}
)
