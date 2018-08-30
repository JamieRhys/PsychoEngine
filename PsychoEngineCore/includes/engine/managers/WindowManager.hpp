//
// Created by Jamie-Rhys Edwards on 30/08/2018.
//

#ifndef PSYCHOENGINE_WINDOWMANAGER_HPP
#define PSYCHOENGINE_WINDOWMANAGER_HPP

#include "engine/api/PsychoEngineExport.hpp"
#include <string>

namespace pe { namespace managers {
    class WindowManager {
    private:
        std::string                 m_windowTitle;
        unsigned int                m_windowWidth, m_windowHeight;

    public:
        PE_API WindowManager(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
        PE_API ~WindowManager() = default;

        /** \brief Sets the window title
         * @param title The window title
         */
        inline void PE_API setWindowTitle(const std::string& windowTitle) { m_windowTitle = windowTitle; }

        /** \brief Gets the window title
         * @return The window title as a string
         */
        inline std::string PE_API getWindowTitle() const { return m_windowTitle; }

        /** \brief Sets the window width
         * @param Window Width
         */
        inline void PE_API setWindowWidth(const unsigned int windowWidth) { m_windowWidth = windowWidth; }

        /** \brief Gets the window width
         * @return Window width as an unsigned integer
         */
        inline unsigned int getWindowWidth() const { return m_windowWidth; }

        /** \brief Sets the window height
         * @param Window height
         */
        inline void PE_API setWindowHeight(const unsigned int windowHeight) { m_windowHeight = windowHeight; }

        /** \brief Gets the window height
         * @param Window height as an unsigned integer
         */
        inline unsigned int getWindowHeight() const { return m_windowHeight; }

    private:
        bool create_window();
    };
}} // namespace pe | namespace managers

#endif //PSYCHOENGINE_WINDOWMANAGER_HPP
