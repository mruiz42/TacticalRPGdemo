cmake_minimum_required(VERSION 3.1)

project(cis29group2game)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest src/main.cpp src/tact/VertexMap.cpp include/tact/VertexMap.h src/tact/Character.cpp
        include/tact/Character.h src/tact/Knight.cpp include/tact/Knight.h
        src/tact/Mage.cpp include/tact/Mage.h src/tact/Tank.cpp include/tact/Tank.h
        src/tact/Ninja.cpp include/tact/Ninja.h src/tact/Spell.cpp include/tact/Spell.h
        src/tact/Castle.cpp include/tact/Castle.h src/tact/Player.cpp include/tact/Player.h)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)