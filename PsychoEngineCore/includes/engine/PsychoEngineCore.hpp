//
// Created by jamie on 28/08/2018.
//

#ifndef PSYCHOENGINE_PSYCHOENGINECORE_HPP
#define PSYCHOENGINE_PSYCHOENGINECORE_HPP

#include "engine/api/PsychoEngineExport.hpp"
#include "managers/WindowManager.hpp"
#include <string>
#include <memory>


namespace pe { namespace engine {
    class PsychoEngineCore {
    private:
        const std::string& m_windowTitle;
        std::unique_ptr<pe::managers::WindowManager> m_windowManager;

    public:
        PE_API PsychoEngineCore()                      = default;
        PE_API PsychoEngineCore(const std::string& windowTitle, int windowWidth, int windowHeight);

    private:
        bool preInit();
        bool init();
        bool postInit();
        void gameLoop();
        void update();
        void render();
        void cleanup();
    };
}} // namespace pe | namespace engine

#endif //PSYCHOENGINE_PSYCHOENGINECORE_HPP
