//
// Created by kyle on 2024/09/24.
//
module;

export module bridge.basic_example.Implementor;

namespace bridge::basic_example {
    export class Implementor {
    public:
        virtual auto OperationImpl() -> void = 0;

        virtual ~Implementor() = default;
    };
}
