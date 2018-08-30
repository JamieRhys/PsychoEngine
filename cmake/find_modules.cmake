set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/find_modules)

if(WIN32)
    set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/gtest/1.7.0/Win32" CACHE PATH "Path to GTest")
    set(EASYLOGGINGPP_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/easyloggingpp/9.96.4/Win32" CACHE PATH "Path to EasyLogging++")
elseif(APPLE)
    set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/gtest/1.7.0/MacOS" CACHE PATH "Path to EasyLogging++")
    set(EASYLOGGINGPP_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/easyloggingpp/9.96.4/MacOS" CACHE PATH "Path To EasyLogging++")
endif(WIN32)


find_package(gtest REQUIRED)
find_package(EasyLOGGINGPP REQUIRED)