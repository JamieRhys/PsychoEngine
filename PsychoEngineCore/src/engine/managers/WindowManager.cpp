//
// Created by Jamie-Rhys Edwards on 30/08/2018.
//

#include "engine/managers/WindowManager.hpp"
#include "easylogging++.h"
#include <string>

namespace pe { namespace managers {
    WindowManager::WindowManager(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight) :
    m_windowTitle(windowTitle),
    m_windowWidth(windowWidth),
    m_windowHeight(windowHeight) {

    }

    bool WindowManager::create_window() {


        return true;
    }
}}