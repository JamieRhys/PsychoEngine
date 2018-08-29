set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/find_modules)

set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/gtest/1.7.0/" CACHE PATH "Path to GTest")
set(EASYLOGGINGPP_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/easyloggingpp/9.96.4/" CACHE PATH "Path to EasyLogging++")
set(BOOST_ROOT )

find_package(gtest REQUIRED)
find_package(EasyLOGGINGPP REQUIRED)