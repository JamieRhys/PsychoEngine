set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/find_modules)

set(GTEST_ROOT "C:/Program Files (x86)/googletest-distribution" CACHE PATH "Path to GTest")
set(EASYLOGGINGPP_ROOT "C:/Program Files (x86)/Easyloggingpp" CACHE PATH "Path to EasyLogging++")

find_package(gtest REQUIRED)
find_package(EasyLOGGINGPP REQUIRED)