//
// Created by jamie on 29/08/2018.
//

#ifndef PSYCHOENGINE_INITLOGGING_HPP
#define PSYCHOENGINE_INITLOGGING_HPP

#include "easylogging++.h"
#include "utils/Files.hpp"
#include <iostream>


INITIALIZE_EASYLOGGINGPP

namespace pe { namespace utils {
    /** Creates a configuration file for EL++
    * @param The name of the file to be used
    */
    void create_log_config(const std::string& filename) {
        std::string dir, path;
#if defined(WIN32)
        dir = "config";
#endif // defined(WIN32)
#if defined(__APPLE__) || defined(__linux__)
        dir = ".config";
#endif // defined(__APPLE__) || defined(__linux__)

        path = dir + "/" + filename;

        create_directory("config", pe::utils::HIDDEN);

        std::ofstream config(path, std::ios::out);

        if(!config) {
            std::cout << "ERROR: Could not open file in location: " << path << std::endl;
            return;
        }

        config << "## Log Configuration File." << std::endl;
        config << "* GLOBAL:" << std::endl;
        config << "		FORMAT					= \"%datetime{%d/%M/%Y} [%level] %msg\"" << std::endl;
        config << "		FILENAME				= \"logs/logging.log\"" << std::endl;
        config << "		ENABLED					= true" << std::endl;
        config << "		TO_FILE					= true" << std::endl;
        config << "		TO_STANDARD_OUTPUT		= true" << std::endl;
        config << "		MILLISECONDS_WIDTH		= 6" << std::endl;
        config << "		PERFORMANCE_TRACKING	= true" << std::endl;
        config << "		MAX_LOG_FILE_SIZE		= 2097154		## 2MB" << std::endl;
        config << "		LOG_FLUSH_THRESHOLD		= 100			## Flush after every 100 logs" << std::endl;
        config << std::endl;
        config << "*DEBUG:" << std::endl;
        config << "		FORMAT					= \"%datetime{%d/%M/%Y} [%level] %func %msg\"" << std::endl;

        config.close();
    }

    void configure_logger(const std::string& filename) {
        std::string path;

#if defined(WIN32)
        path = "config";
#endif // defined(WIN32)
#if defined(__APPLE__) || defined(__linux__)
        path = ".config";
#endif
        path += "/" + filename;

        if(!does_file_exist(path)) {
            create_log_config(path);
        }

        // If we get this far then load the config file.
        el::Configurations config(path);

        // Configure all loggers
        el::Loggers::reconfigureAllLoggers(config);
    }
}}

#endif //PSYCHOENGINE_INITLOGGING_HPP
