cmake_minimum_required(VERSION 3.1)

project(cis29group2game)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest src/main.cpp src/fxx/VertexMap.cpp src/fxx/VertexMap.h src/Characters/Character.cpp src/include/Character.h src/Characters/Knight.cpp src/include/Knight.h src/Characters/Mage.cpp src/include/Mage.h src/Characters/Tank.cpp src/include/Tank.h src/Characters/Ninja.cpp src/include/Ninja.h src/Characters/Spell.cpp src/include/Spell.h src/Characters/Castle.cpp src/include/Castle.h src/Characters/Player.cpp src/include/Player.h)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)