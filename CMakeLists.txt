cmake_minimum_required(VERSION 3.1)

# так пишутся комментарии

project(oop_exercise_03)

find_library(PTHREAD_LIBRARY pthread)
find_library(PCRE_LIBRARY pcre)

include_directories(include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(main oop_exercise_03.cpp Figure.cpp)

target_link_libraries(main ${PTHREAD_LIBRARY} ${PCRE_LIBRARY})
