//
// Created by jamie on 28/08/2018.
//

#include "engine/PsychoEngineCore.hpp"
#include "utils/initLogging.hpp"
#include <iostream>

namespace pe { namespace engine {
/*
 * Public Functions
 */
    PsychoEngineCore::PsychoEngineCore(const std::string& windowTitle) :
    m_windowTitle(windowTitle) {
        pe::utils::create_log_config();
    }

/*
 * Private Functions
 */
    bool PsychoEngineCore::preInit() {

    }

    bool PsychoEngineCore::init() {

    }

    bool PsychoEngineCore::postInit() {

    }

    void PsychoEngineCore::gameLoop() {

    }

    void PsychoEngineCore::update() {

    }

    void PsychoEngineCore::render() {

    }

    void PsychoEngineCore::cleanup() {

    }
}} // namespace pe | namespace engine