//
// Created by Kyle on 2024/03/16.
//
module;

#include <string>

export module facade.console_project.ConsoleLinux;

import facade.console_project.Console;

namespace facade::console_project
{
    export class ConsoleLinux
    {
        ConsoleLinux();
        static void SetColour(Colour colour);

    public:
        static void Write(const std::string& text, Colour colour = Colour::WHITE);

        static void WriteLine(const std::string& text, Colour colour = Colour::WHITE);
    };
}