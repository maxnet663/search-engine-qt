cmake_minimum_required(VERSION 3.21)
project(search_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/interface)

set(CMAKE_PREFIX_PATH "/home/maxnet/Qt/5.15.2/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_subdirectory(src)

set(FILES_TO_BUILD
        include/mainwindow.h
        src/mainwindow.cpp
        include/file_manager.h
        src/file_manger.cpp
        include/inverted_index.h
        src/inverted_index.cpp
        src/main.cpp
)

add_executable(search_engine ${FILES_TO_BUILD})

target_include_directories(search_engine PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(search_engine
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

add_compile_definitions(PROJECT_PATH="${CMAKE_SOURCE_DIR}")