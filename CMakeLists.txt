cmake_minimum_required(VERSION 3.17)
project(hello_sfml)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_NAME "hello_sfml")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Frameworks)

add_executable(${EXECUTABLE_NAME}
        srcs/main.cpp
        srcs/classes/canonball_t.cpp
        srcs/classes/scope_t.cpp
        srcs/classes/cannon_t.cpp
        srcs/utils.cpp
        srcs/classes/wrap_window.cpp
        srcs/classes/target_c1.cpp
        srcs/classes/interaction.cpp
        srcs/classes/canonball_t.hpp
        srcs/classes/scope_t.hpp
        srcs/shooting_range.hpp
        srcs/classes/cannon_t.hpp
        srcs/classes/wrap_window.hpp
        srcs/classes/target_c1.hpp
        srcs/classes/interaction_objects.hpp
        srcs/classes/interaction.hpp
        srcs/classes/bomb.cpp
        srcs/classes/bomb.hpp
        srcs/classes/logic.cpp
        srcs/classes/logic.hpp
        srcs/classes/config/Config.cpp
        srcs/classes/config/Config.hpp
        )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/.)

link_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${EXECUTABLE_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-audio.dylib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-graphics.dylib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-network.dylib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-system.dylib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsfml-window.dylib
        )

