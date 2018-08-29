//
// Created by jamie on 29/08/2018.
//

#ifndef PSYCHOENGINE_FILES_HPP
#define PSYCHOENGINE_FILES_HPP

#ifdef WIN32
#   include <windows.h>
#endif

#include <fstream>
#include <string>

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
     * @param dirName The name of the directory to be checked
     * @return True if exists, false otherwise
    */
    bool does_directory_exist(const std::string& dirName) {
#ifdef WIN32
       DWORD ftyp = GetFileAttributesA(dirName.c_str());
       if(ftyp == INVALID_FILE_ATTRIBUTES) {
           return false; /*< Something is wrong with the path */
       }

       if(ftyp & FILE_ATTRIBUTE_DIRECTORY) {
           return true; /*< This is a directory */
       } else {
           return false; /*< This is not a directory */
       }
#endif
    }

    /** Creates a directory
     * @param dirName The name of the directory to be created
     * @param fv The visiblity of the directory
     * @return True if creation was successful, false otherwise
    */
    bool create_directory(const std::string& dirName, const FILE_VISIBILITY fv) {
#ifdef WIN32
           if (CreateDirectory(dirName.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError()) {
               if(fv == pe::utils::HIDDEN) {
                   SetFileAttributes(dirName.c_str(), FILE_ATTRIBUTE_HIDDEN);
               }
               return true; /*< Successfully created directory */
           } else {
               return false; /*< Unsuccessful. May already exist? */
           }
#endif
    }

}} // namespace pe | namespace utils

#endif //PSYCHOENGINE_FILES_HPP
