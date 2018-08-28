# Look in PsychoEngine CMakeLists.txt for minimum CMake version
cmake_minimum_required(VERSION ${PROJECT_CMAKE_MIN_VERSION} FATAL_ERROR)

project(LibTest CXX)

set(SRCS_TEST ${CMAKE_CURRENT_LIST_DIR})
set(INCS_TEST ${CMAKE_CURRENT_LIST_DIR}/includes)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_SOURCE_DIR}/PsychoEngineCore/includes)
include(${CMAKE_CURRENT_LIST_DIR}/src/dir_src.cmake)

link_directories(${CMAKE_BINARY_DIR}/PsychoEngineCore)

add_executable(${PROJECT_NAME} ${SRCS_TEST} ${INCS_TEST})

if(LIB_TYPE MATCHES STATIC)
    target_link_libraries(${PROJECT_NAME} PsychoEngineCore_s)
else()
    target_link_libraries(${PROJECT_NAME} PsychoEngineCore)
endif(LIB_TYPE MATCHES STATIC)