//
// Created by kyle on 2024/09/20.
//

module;
#include <iostream>


export module bridge.shared_implementation.main;

import bridge.shared_implementation.String;


namespace bridge::shared_implementation
{
    export auto main_shared_implementation() -> void
    {
        String s{"C++"};
        auto s2{s};
        std::cout << "String:" << s.GetString() << std::endl;
        std::cout << "Length:" << s.GetLength() << std::endl;
    }
}
