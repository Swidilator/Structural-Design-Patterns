//
// Created by Kyle on 2024/09/28.
//
module;
#include <ostream>

export module flyweight.game_assets.Model;

namespace flyweight::game_assets
{
    export struct Position3D
    {
        int x, y, z;

        friend auto operator<<(std::ostream& os, const Position3D& obj) -> std::ostream&
        {
            return os
                << "(" << obj.x
                << ", " << obj.y
                << ", " << obj.z
                << ")\n";
        }
    };


    export class Model
    {
    public:
        virtual auto Render() -> void;
        virtual auto Render(Position3D position) -> void;
        virtual ~Model() = default;
    };
}
