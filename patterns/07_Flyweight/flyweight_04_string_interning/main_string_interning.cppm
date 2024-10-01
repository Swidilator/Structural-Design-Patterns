//
// Created by kyle on 2024/09/20.
//

module;
#include <memory>
#include <iostream>
#include <vector>

export module flyweight.string_interning.main;

import flyweight.string_interning.String;


namespace flyweight::string_interning
{
    export auto main_string_interning() -> void
    {
        std::vector<String> strings{};
        for (int i = 0; i < 100; ++i)
        {
            strings.emplace_back("C++");
        }
        strings[0] = "Java";
        strings[1] = "C++";

        String s1 = "C++";
        String::ShowCount();
        StringInfo::ShowCount();
    }
}
