cmake_minimum_required(VERSION 2.8)

project (Lab28_examle)
set(SOURCES Source.cpp)
add_executable (${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Lab28)
