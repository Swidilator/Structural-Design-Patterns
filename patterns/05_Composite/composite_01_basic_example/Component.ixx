//
// Created by kyle on 2024/09/20.
//
module;

export module composite.basic_example.Component;

namespace composite::basic_example {
    export class Component {
    public:
        virtual auto Operation() -> void = 0;

        virtual auto Add(Component *pComponent) -> void = 0;

        virtual auto Remove(Component *pComponent) -> void = 0;

        virtual auto GetChild(int index) -> Component * = 0;

        virtual ~Component() = default;
    };
}
