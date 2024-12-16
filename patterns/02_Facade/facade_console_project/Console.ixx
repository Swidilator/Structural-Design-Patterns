//
// Created by Kyle on 2024/03/09.
//
module;

#include <iostream>

export module facade.console_project.Console;

namespace facade::console_project
{
    export enum class Colour
    {
        RED, GREEN, BLUE, WHITE
    };

    export class Console
    {
    public:
        Console() = default;
        virtual auto Write(const std::string& text, Colour colour = Colour::WHITE) -> void = 0;

        virtual auto WriteLine(const std::string& text, Colour colour = Colour::WHITE) -> void = 0;

        virtual ~Console() = 0;
    };

    Console::~Console()
    {
    }



    // Old windows-based non-facade implementation
    // auto non_facade_colour_code() -> void
    // {
    //     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //     CONSOLE_SCREEN_BUFFER_INFO csinfo{};
    //     if(!GetConsoleScreenBufferInfo(hConsole, &csinfo))
    //     {
    //         std::cout << "Error getting console information" << std::endl;
    //     }
    //     SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    //     std::string text{"Hello WriteConsoleA\n"};
    //     DWORD written{};
    //     WriteConsoleA(hConsole, text.c_str(), text.length(), &written, nullptr);
    //     std::cout << "Hello cout" << std::endl;
    //
    //     SetConsoleTextAttribute(hConsole, csinfo.wAttributes);
    //
    //     WriteConsoleA(hConsole, text.c_str(), text.length(), &written, nullptr);
    //     std::cout << "Hello cout" << std::endl;
    // }
}
