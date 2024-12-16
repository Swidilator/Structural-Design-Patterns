//
// Created by Kyle on 2024/09/28.
//
module;
#include <vector>
#include <string>
#include <string_view>

export module flyweight.game_assets.Vegetation;

import flyweight.game_assets.Model;


namespace flyweight::game_assets
{
    export class Vegetation
        : public Model
    {
        inline static int m_Count{};
        std::vector<int> m_MeshData;
        const char* m_Texture{};
        std::string m_Tint{};
        Position3D m_Position{};

    public:
        Vegetation(std::string_view tint, Position3D position);

        auto Render() -> void override;
        static auto ShowCount() -> void;
    };
}
