cmake_minimum_required(VERSION 3.17)
#set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_OSX_SYSROOT
        "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")
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
