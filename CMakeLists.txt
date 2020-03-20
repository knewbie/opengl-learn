cmake_minimum_required(VERSION 3.9)

project(LearnGL VERSION 1.0)

add_executable(LearnGL src/main.cxx)

set(ALL_LIBS glfw GL X11 pthread Xrandr Xi)

target_link_libraries(LearnGL ${ALL_LIBS})
