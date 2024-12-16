//
// Created by kyle on 2024/09/20.
//

module;

export module bridge.basic_example.main;
import bridge.basic_example.ConcreteImplementorA;
import bridge.basic_example.ConcreteImplementorB;

import bridge.basic_example.Abstraction;
import bridge.basic_example.RefinedAbstraction;

namespace bridge::basic_example {
    export auto main_basic_example() -> void {
        ConcreteImplementorB impl{};
        Abstraction *p = new RefinedAbstraction{&impl};
        p->Operation();
    }
}
