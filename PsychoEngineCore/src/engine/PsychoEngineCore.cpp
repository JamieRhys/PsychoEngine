//
// Created by jamie on 28/08/2018.
//

#include "engine/PsychoEngineCore.hpp"
#include "utils/InitLogging.hpp"
#include "config/PsychoEngineConfig.hpp"
#include <iostream>

namespace pe { namespace engine {
/*
 * Public Functions
 */
    PsychoEngineCore::PsychoEngineCore(const std::string& windowTitle, int windowWidth, int windowHeight) :
    m_windowTitle(windowTitle),
    m_windowManager(std::make_unique<pe::managers::WindowManager>(windowTitle, windowWidth, windowHeight)) {
        // Initialise our logger before all else
        pe::utils::configure_logger("pe_log.config");

        LOG(INFO) << "Window Title: " <<m_windowManager->getWindowTitle() << std::endl <<
        "Window Width: " << m_windowManager->getWindowWidth() << std::endl <<
        "Window Height: " << m_windowManager->getWindowHeight() << std::endl;



        LOG(INFO) << "PsychoEngineCore version: v" << PE_VERSION_FULL;

        // Pre-initialise the engine
        preInit();

        // Initialise the engine
        init();

        // Post-initialise the engine
        postInit();

        // Initiate the game loop.
        LOG(INFO) << "Starting Engine loop.";
        gameLoop();

        // Clean up any resources we may have used
        cleanup();
    }

/*
 * Private Functions
 */
    bool PsychoEngineCore::preInit() {
        LOG(INFO) << "Pre-initialising Engine...";
        return false;
    }

    bool PsychoEngineCore::init() {
        LOG(INFO) << "Initialising Engine...";
        return false;
    }

    bool PsychoEngineCore::postInit() {
        LOG(INFO) << "Post-initialising Engine.";
        return false;
    }

    void PsychoEngineCore::gameLoop() {
        update();
        render();
    }

    void PsychoEngineCore::update() {
    }

    void PsychoEngineCore::render() {

    }

    void PsychoEngineCore::cleanup() {
        LOG(INFO) << "Starting Engine Cleanup...";
    }
}} // namespace pe | namespace engine