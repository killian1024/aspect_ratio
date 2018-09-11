cmake_minimum_required(VERSION 3.9)

project(aspect_ratio)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SOURCE_FILES
        src/main.cpp
        )

add_executable(aspect_ratio ${SOURCE_FILES})
target_link_libraries(aspect_ratio -lspeed -lstdc++fs)
install(TARGETS aspect_ratio DESTINATION bin)
