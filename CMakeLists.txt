cmake_minimum_required(VERSION 3.27)
project(ParticlesTask)

include(Cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        Source/Main.cpp
        Source/UserInterface.cpp
        Source/VBox.cpp
        Source/Label.cpp
        Source/ParticleSystem.cpp)

add_executable(ParticlesTask ${SOURCES})

target_include_directories(ParticlesTask PRIVATE Include)

# Add raylib
CPMAddPackage(
    NAME raylib
    GIT_TAG 5.0
    GITHUB_REPOSITORY raysan5/raylib
)

target_link_libraries(ParticlesTask PRIVATE raylib)

if(${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an ParticlesTask.html file.
    set_target_properties(ParticlesTask PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if(APPLE)
    target_link_libraries(ParticlesTask "-framework IOKit")
    target_link_libraries(ParticlesTask "-framework Cocoa")
    target_link_libraries(ParticlesTask "-framework OpenGL")
endif()