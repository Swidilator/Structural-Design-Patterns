//
// Created by kyle on 2024/08/02.
//

module;

#include <iostream>
#include <string>

export module decorator.functional.main;





namespace decorator::functional
{

    auto Square(int x) -> int {
        return x * x;
    }

    auto Add(int x, int y) -> int {
        return x + y;
    }

    auto Divide(float x, float y) {
        return x / y;
    }

    template<typename Function>
    auto PrintResult(Function func) {
        return [func](auto&&...args) {
            std::cout << "Result is: " ;
            return func(args...);
        };
    }

    template<typename Function>
        auto PrintHeader(Function func) {
        return [func](auto&&...args) {
            std::cout << "================\n";
            return func(args...);
        };
    }

    template<typename Function>
    auto SafeDivision(Function func) {
        return [func](auto a, auto b) {
            if (b== 0) {
                std::cout << "Divide by zero " ;
                b=1;
            }

            return func(a, b);
        };
    }

    export auto main_functional() -> void
    {
        // auto result = Square(5);
        // std::cout << result << std::endl;

        auto result = PrintResult(Square);
        std::cout << result(5) << std::endl;

        auto add = PrintResult(Add);
        std::cout << add(5,6) << std::endl;

        auto divide = PrintHeader(PrintResult(SafeDivision(Divide)));
        std::cout << divide(5,0) << std::endl;
    }
}
