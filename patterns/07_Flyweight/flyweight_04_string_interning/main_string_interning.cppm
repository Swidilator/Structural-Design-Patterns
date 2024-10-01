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
        String s1{"C++"};
        String s2{"C++"};

        std::cout << static_cast<const void*>(s1.GetString()) << ":" << s1 << std::endl;
        std::cout << static_cast<const void*>(s2.GetString()) << ":" << s2 << std::endl;
    }
}
