//
// Created by jamie on 29/08/2018.
//

#ifndef PSYCHOENGINE_INITLOGGING_HPP
#define PSYCHOENGINE_INITLOGGING_HPP

#include "easylogging++.h"
#include "utils/files.hpp"
#include <iostream>

INITIALIZE_EASYLOGGINGPP

namespace pe { namespace utils {
    /** Creates a configuration file for EL++
    * @param The name of the file to be used
    */
    void create_log_config() {
        char buffer[MAX_PATH];
        std::string path;
#ifdef WIN32

        char buffer[MAX_PATH];
        std::string path;

        //TCHAR path[512];
        DWORD length;

        length = GetModuleFileName(nullptr, buffer, MAX_PATH);

        std::string::size_type pos = std::string(buffer).find_last_of("\\/");
        path = std::string(buffer).substr(0, pos);
#endif
    }
}}

#endif //PSYCHOENGINE_INITLOGGING_HPP
