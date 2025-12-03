cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME TravelRegister)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" main.cpp skelet_logic.cpp CPP/major_func.cpp CPP/ui.cpp CPP/supp_func.cpp) 