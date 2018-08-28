# Define the minimum required version of CMake in a variable so as to allow cross project simplicity
set(PROJECT_CMAKE_MIN_VERSION 3.12)

# Set the minimum version for CMake
cmake_minimum_required(VERSION ${PROJECT_CMAKE_MIN_VERSION} FATAL_ERROR)

project(PsychoEngine)

# Set our version information (used in our configuration file
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)

# Set our CXX standard to 17
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

message("-- ${PROJECT_NAME}: Starting build...")

set(LIB_TYPE "STATIC" CACHE STRING "Dynamic or Shared linking")

# Find modules
include(cmake/find_modules.cmake)

# Do we want to build the test project too? Currently set to true.
option(BUILD_TEST "Build the library test project?" ON)

# Create and place our configuration header in the core include directory
message("-- ${PROJECT_NAME}: Creating configuration header")
include(cmake/config_header.cmake)

message("-- ${PROJECT_NAME}: Building ${PROJECT_NAME}Core")
add_subdirectory(${PROJECT_NAME}Core)

if(BUILD_TEST MATCHES ON)
    message("-- ${PROJECT_NAME}: Building test project")
    add_subdirectory(LibTest)
endif(BUILD_TEST MATCHES ON)

export(PACKAGE ${PROJECT_NAME})

install(DIRECTORY ${CMAKE_BINARY_DIR}/build/lib
                    ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}Core/includes
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        COMPONENT dev)