cmake_minimum_required(VERSION 3.5)
project(ray_casting_game)

set(CMAKE_CXX_STANDARD 17)


# Create an option to switch between a system sdl library and a vendored sdl library
option(RAY_CASTING_VENDORED "Use vendored libraries" OFF)

# SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    #include the header files folder
    include
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

file(GLOB SOURCES
    src/*.cpp
    main.cpp
)

if(RAY_CASTING_VENDORED)
    add_subdirectory(vendored/sdl EXCLUDE_FROM_ALL)
else()
    # 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
    find_package( SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2 )

    # 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

# Create your game executable target as usual
add_executable(ray_casting_game ${SOURCES}

)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    target_link_libraries(ray_casting_game
    SDL2::SDL2
    SDL2_ttf::SDL2_ttf
)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is
