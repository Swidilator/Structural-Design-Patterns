//
// Created by Kyle on 2024/03/09.
//
module;
#include <iostream>
#include <string>

export module facade.console_project.main;

import facade.console_project.Console;
import facade.console_project.ConsoleWindows;

// Assignment: Write separate child classes, one for windows, one for linux, that implement the functionality and let
// user use the correct one through a parent console class

namespace facade::console_project
{
    export auto main_console_project() -> void
    {
        ConsoleWindows c;
        c.WriteLine("Hello there", Colour::GREEN);
        c.Write("This is the first half in red, ", Colour::RED);
        c.Write("this is the second half in blue ", Colour::BLUE);
        std::cout << std::endl;

        // ConsoleLinux::WriteLine("Hello there", Colour::GREEN);
        // ConsoleLinux::Write("This is the first half in red, ", Colour::RED);
        // ConsoleLinux::Write("this is the second half in blue ", Colour::BLUE);
        // std::cout << std::endl;
    }
}
