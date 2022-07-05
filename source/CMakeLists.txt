cmake_minimum_required(VERSION 3.5)

project(test_prog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_prog main.cpp datacreate.cpp datacreate.h datetest.cpp datetest.h
               programbegin.cpp programbegin.h interface.h users.h users.cpp createusers.cpp
               createusers.h changeuser.h changeuser.cpp base_for_program.h base_for_program.cpp)
