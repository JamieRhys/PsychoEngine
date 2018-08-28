# Creates and places our configuration header into the core include directory
set(PROJECT_CONFIG_INCLUDE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}Core/includes/config/${PROJECT_NAME}Config.hpp)

configure_file(
        "cmake/cmake_includes/config/${PROJECT_NAME}Config.hpp.in"
        "${PROJECT_CONFIG_INCLUDE}"
)