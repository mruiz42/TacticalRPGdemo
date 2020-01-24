cmake_minimum_required(VERSION 3.1)

project(cis29group2game)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest src/main.cpp src/tct/VertexMap.cpp src/tact/VertexMap.h src/tact/Characters/Character.cpp
        src/tact/include/Character.h src/tact/Characters/Knight.cpp src/tact/include/Knight.h
        src/tact/Characters/Mage.cpp src/tact/include/Mage.h src/tact/Characters/Tank.cpp src/tact/include/Tank.h
        src/tact/Characters/Ninja.cpp src/include/Ninja.h src/Characters/Spell.cpp src/include/Spell.h
        src/Characters/Castle.cpp src/include/Castle.h src/Characters/Player.cpp src/include/Player.h src/tact/test.cpp
        include/tact/test.h)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)