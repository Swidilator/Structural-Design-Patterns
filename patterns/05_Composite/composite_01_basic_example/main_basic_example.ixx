//
// Created by kyle on 2024/09/20.
//

module;

export module composite.basic_example.main;

import composite.basic_example.Leaf;
import composite.basic_example.Composite;
//import composite.basic_example.Component;

namespace composite::basic_example {
    export auto main_basic_example() -> void {
        Leaf leaf1, leaf2, leaf3;

        Composite subroot;
        subroot.Add(&leaf3);

        Composite root;
        root.Add(&leaf1);
        root.Add(&leaf2);
        root.Add(&subroot);

        root.Operation();
    }
}
