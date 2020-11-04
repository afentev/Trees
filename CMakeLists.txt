cmake_minimum_required(VERSION 3.17)
project(Trees)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(Trees main.cpp Trees/bst.cpp Trees/bst.h Trees/avl.cpp Trees/avl.h
               Trees/rbt.cpp Trees/rbt.h Trees/rbst.cpp Trees/rbst.h Trees/syncedtrees.cpp
               Trees/syncedtrees.h UIstuff/mw.cpp UIstuff/mw.h Trees/Tree.h)

target_link_libraries(Trees Qt5::Core Qt5::Widgets)
