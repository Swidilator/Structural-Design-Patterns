//
// Created by Kyle on 2024/03/16.
//
module;

#include <string>
#include <windows.h>


export module facade.console_project.ConsoleWindows;

import facade.console_project.Console;

namespace facade::console_project
{
    export class ConsoleWindows
        : public Console
    {
        HANDLE m_Std;
        //CONSOLE_SCREEN_BUFFER_INFO m_consoleBufferInfo{};
        //static ConsoleWindows m_Instance;

        auto GetColour(Colour colour) -> WORD;

    public:
        ConsoleWindows();
        // ~Console()
        // {
        //     SetConsoleTextAttribute(m_Std, m_consoleBufferInfo.wAttributes);
        // }

        ~ConsoleWindows() override = default;

        auto Write(const std::string& text, Colour colour = Colour::WHITE) -> void override;

        auto WriteLine(const std::string& text, Colour colour = Colour::WHITE) -> void override;
    };

    //ConsoleWindows ConsoleWindows::m_Instance;
}