# Check PsychoEngine CMakeLists.txt for CMake version
cmake_minimum_required(VERSION ${PROJECT_CMAKE_MIN_VERSION} FATAL_ERROR)

project(${PROJECT_NAME}Core CXX)

set(SRCS_CXX ${CMAKE_CURRENT_LIST_DIR})
set(INCS_CXX ${INCS_CXX})
set(PROJ_LIB ${PROJ_LIB})

include(${CMAKE_CURRENT_SOURCE_DIR}/src/dir_src.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${INCS_CXX}
        ${EASYLOGGINGPP_INCLUDE_DIR}
)

if(LIB_TYPE MATCHES STATIC)
    if(UNIX AND NOT APPLE)
        set(CMAKE_FIND_LIBRARY_SUFFIXES(".a"))
    endif(UNIX AND NOT APPLE)

    set(CMAKE_EXE_LINKER_FLAGS "-static")
    #set_target_properties(surface PROPERTIES LINK_SEARCH_END_STATIC 1)

    set(FINAL_PROJECT_NAME ${PROJECT_NAME}_s)
else()
    set(FINAL_PROJECT_NAME ${PROJECT_NAME})
endif(LIB_TYPE MATCHES STATIC)

include(GenerateExportHeader)
add_library(${FINAL_PROJECT_NAME} ${LIB_TYPE} ${SRCS_CXX})
target_link_libraries(${FINAL_PROJECT_NAME} ${PROJ_LIB})
generate_export_header(
        ${FINAL_PROJECT_NAME}
        EXPORT_MACRO_NAME PE_API
        NO_EXPORT_MACRO_NAME PE_NO_EXPORT
        EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/includes/engine/api/PsychoEngineExport.hpp
        DEPRECATED_MACRO_NAME PE_API_DEP
        STATIC_DEFINE PE_STATIC
)
target_include_directories(${FINAL_PROJECT_NAME}
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/includes"
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src"
)