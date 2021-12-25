cmake_minimum_required(VERSION 3.20)
project(SFMLproject)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5 COMPONENTS graphics)

add_executable(SFMLproject main.cpp Castle/Castle.cpp Castle/Castle.h Game/Game.h Game/Game.cpp Enemy/Enemy.cpp Enemy/Enemy.h Point.h Tower/Tower.cpp Tower/Tower.h Liar/Liar.cpp Liar/Liar.h Effect/Effect.cpp Effect/Effect.h Loader/Loader.cpp Loader/Loader.h TemplateTable/TemplateTable.h Loader/EnemyData/EnemyInfo.h Loader/EnemyData/EnemyInfo.cpp SlowEffect/SlowEffect.cpp SlowEffect/SlowEffect.h)

target_link_libraries(SFMLproject sfml-graphics)
