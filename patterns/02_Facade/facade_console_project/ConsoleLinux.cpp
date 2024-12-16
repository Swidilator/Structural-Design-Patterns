//
// Created by Kyle on 2024/03/16.
//

module;

#include <iostream>

module facade.console_project.ConsoleLinux;

namespace facade::console_project
{
    void ConsoleLinux::SetColour(Colour colour)
    {
        switch (colour)
        {
        case Colour::RED:
            std::cout << "\033[31m";
            break;
        case Colour::BLUE:
            std::cout << "\033[32m";
            break;
        case Colour::GREEN:
            std::cout << "\033[34m";
            break;
        case Colour::WHITE:
            std::cout << "\033[00m";
            break;
        }
    }

    void ConsoleLinux::Write(const std::string& text, Colour colour)
    {
        SetColour(colour);
        std::cout << text;
        SetColour(Colour::WHITE);
    }

    void ConsoleLinux::WriteLine(const std::string& text, Colour colour)
    {
        Write(text + "\n", colour);
    }
}
