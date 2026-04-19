cmake_minimum_required(VERSION 3.10)
project(Lab4 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(lab4 
    src/main.cpp
    src/circle.cpp
    src/list.cpp
    src/point.cpp
    src/my_string.cpp
)

add_executable(lab4 ${lab4})

target_include_directories(lab4 PRIVATE include)

add_custom_command(TARGET lab4 POST_BUILD
    
    COMMAND $<TARGET_FILE:lab4>
    COMMENT "Запуск собранного приложения..."
)
