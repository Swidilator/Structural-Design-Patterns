//
// Created by kyle on 2024/09/20.
//

module;
#include <iostream>


export module bridge.shared_implementation.main;

import bridge.shared_implementation.String;
import bridge.shared_implementation.SharedString;


namespace bridge::shared_implementation
{
    export auto main_shared_implementation() -> void
    {
        SharedString s{"C++"};
        auto s2{s};
        auto s3 = std::move(SharedString{"C++"});

        // std::cout << "String:" << s.GetString() << std::endl;
        // std::cout << "Length:" << s.GetLength() << std::endl;
    }
}
