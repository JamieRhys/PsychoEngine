//
// Created by jamie on 28/08/2018.
//

#ifndef PSYCHOENGINE_PSYCHOENGINECORE_HPP
#define PSYCHOENGINE_PSYCHOENGINECORE_HPP

#include "engine/api/PsychoEngineExport.hpp"
#include <string>

namespace pe { namespace engine {
    class PsychoEngineCore {
    private:
        const std::string& m_windowTitle;

    public:
        PE_API PsychoEngineCore()                      = default;
        PE_API PsychoEngineCore(const std::string& windowTitle);

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
