cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloGoogleTest)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the GoogleTest library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# add the executable
set(SOURCE_FILES testingMario.cpp Driver/Driver.cpp Driver/KartDriver.cpp Driver/MotorcycleDriver.cpp Driver/ATVDriver.cpp Garage.cpp)
add_executable(HelloGoogleTest ${SOURCE_FILES})


# link the GoogleTest library
target_link_libraries(HelloGoogleTest ${GTEST_LIBRARIES} pthread)

