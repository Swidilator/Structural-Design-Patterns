//
// Created by Kyle on 2024/04/28.
//
module;

export module adapter.basic_example.main;

import adapter.basic_example.basic_classes;

namespace adapter::basic_example
{
    export auto main_adapter_basic() -> void
    {
        ObjectAdapter a1;
        ClassAdapter a2;
        client(&a1);
        client(&a2);
    }
}