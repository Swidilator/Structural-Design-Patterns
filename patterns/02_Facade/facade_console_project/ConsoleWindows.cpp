//
// Created by Kyle on 2024/03/16.
//
module;

#include <string>
#include <stdexcept>
#include <windows.h>

module facade.console_project.ConsoleWindows;


import facade.console_project.Console;



namespace facade::console_project
{
    auto ConsoleWindows::GetColour(Colour colour) -> WORD
    {
        switch (colour)
        {
        case Colour::RED:
            return FOREGROUND_RED;
        case Colour::BLUE:
            return FOREGROUND_BLUE;
        case Colour::GREEN:
            return FOREGROUND_GREEN;
        }
        return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
Tana Core
    ConsoleWindows::ConsoleWindows()
    {
        m_Std = GetStdHandle(STD_OUTPUT_HANDLE);
        // if (!GetConsoleScreenBufferInfo(m_Std, &m_consoleBufferInfo))
        // {
        //     throw std::runtime_error{"Error while retrieving console information"};
        // }
    }

    auto ConsoleWindows::Write(const std::string& text, Colour colour) -> void
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi{};
        if (!GetConsoleScreenBufferInfo(m_Std, &csbi))
        {
            throw std::runtime_error{"Error while retrieving console information"};
        }
        SetConsoleTextAttribute(m_Std, GetColour(colour));

        DWORD written{};
        WriteConsoleA(m_Std, text.c_str(), text.length(), &written, nullptr);
        SetConsoleTextAttribute(m_Std, csbi.wAttributes);
    }

    auto ConsoleWindows::WriteLine(const std::string& text, Colour colour) -> void
    {
        Write(text + "\n", colour);
    }
}
