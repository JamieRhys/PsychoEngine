//
// Created by jamie on 29/08/2018.
//

#ifndef PSYCHOENGINE_FILES_HPP
#define PSYCHOENGINE_FILES_HPP

#if defined(WIN32)
#   include <windows.
#endif // defined(WIN32)

#if defined (__APPLE__) || defined (__linux__)
#   include <unistd.h>
#   include <sys/stat.h>
#endif // defined (__APPLE__) || defined (__linux__)

#include <fstream>
#include <string>
#include <iostream>

namespace pe { namespace utils {
    enum FILE_VISIBILITY {
        VISIBLE             = 0,
        HIDDEN              = 1
    };

    /** Checks if given file exists
     * @param filename The name of the file to be checked
     * @return True if exists, false otherwise
    */
    bool does_file_exist(const std::string& filename) {
      std::ifstream i(filename);
      return i.good();
    }

    /** Checks if given directory exists
     * @param path The name of the directory to be checked
     * @return True if exists, false otherwise
    */
    bool does_directory_exist(const std::string& path) {
#if defined(WIN32)
       DWORD ftyp = GetFileAttributesA(path.c_str());
       if(ftyp == INVALID_FILE_ATTRIBUTES) {
           return false; /*< Something is wrong with the path */
       }

       if(ftyp & FILE_ATTRIBUTE_DIRECTORY) {
           return true; /*< This is a directory */
       } else {
           return false; /*< This is not a directory */
       }
#endif // defined(WIN32)

#if defined(__APPLE__) || defined(__linux__)

        // TODO: CHECK ACTUALLY WORKS ON LINUX!
        struct stat st;
        if(stat(path.c_str(), &st) == 0) {
            return true;
        } else {
            return false;
        }
#endif // defined (__APPLE__) || (__linux__)
    }

    /** Creates a directory
     * @param dirName The name of the directory to be created
     * @param fv The visiblity of the directory
     * @return True if creation was successful, false otherwise
    */
    bool create_directory(const std::string& dirName, const FILE_VISIBILITY fv) {
#if defined(WIN32)
        if (CreateDirectory(dirName.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
            if(fv == pe::utils::HIDDEN) {
                SetFileAttributes(dirName.c_str(), FILE_ATTRIBUTE_HIDDEN);
           }
           return true; /*< Successfully created directory */
        } else {
            if(does_directory_exist(dirName)) {
                std::cout << "Directory already exists" << std::endl;
            }
           return false; /*< Unsuccessful. May already exist? */
        }
#endif // defined(WIN32)

#if defined (__APPLE__) || defined (__linux__)
        if(fv == pe::utils::HIDDEN) {
            const std::string& dn = "." + dirName;

            if(mkdir(dn.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != -1) {
                return true; // Creation was successful.
            } else {
                return false; // Creation was unsuccessful.
            }
        } else if(fv == pe::utils::VISIBLE) {
            if(mkdir(dirName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != -1) {
                return true; // Creation was successful.
            } else {
                return false; // Creation was unsuccessful.
            }
        }
#endif // defined (__APPLE__) || defined (__linux__)

        return false;
    }

}} // namespace pe | namespace utils

#endif //PSYCHOENGINE_FILES_HPP
