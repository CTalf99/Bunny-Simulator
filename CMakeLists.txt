#minimum version of CMake  
cmake_minimum_required(VERSION 3.10)

#Minimum version of C++ (referred to as CXX in CMake)
set(CMAKE_CXX_STANDARD 20)

#if your compiler isn't compatible with the above 
#this will prevent falling back to the last compatible version
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#The project name and version
project(Bunnies VERSION 1.0)

##NOTE##
#this is a way to auto detect all the cpp files you have in a directory
#this isnt reccomended
#file(GLOB_RECURSE SRC_FILES src/*.cpp )

#this is a variable which lists all the cpp files you will need to link
set(SRC_FILES src/BunnyManager.cpp src/Bunny.cpp src/generator.cpp)


#The executable name and where the main function is
add_executable(${PROJECT_NAME} src/main.cpp ${SRC_FILES})

#orriginally used to specify language features you need 
#and CMake will auto detect the minimum version needed
#this can also be used to force a minimum version (alt to ln 5 & 9)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

#this is how you include all your header files
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)