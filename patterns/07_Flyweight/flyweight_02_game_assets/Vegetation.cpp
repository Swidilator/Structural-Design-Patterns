//
// Created by Kyle on 2024/09/28.
//
module;
#include <iostream>

module flyweight.game_assets.Vegetation;

namespace flyweight::game_assets
{
    Vegetation::Vegetation(std::string_view tint, Position3D position)
        : m_Tint{tint}, m_Position{position}
    {
        ++m_Count;
        m_MeshData.assign({5, 1, 2, 8, 2, 9});
        m_Texture = R"(
    #
   ###
  #####
 #######
#########
    #
    #
)";
    }

    void Vegetation::Render()
    {
        std::cout << m_Texture;
        std::cout << "Mesh: ";
        for (auto m : m_MeshData)
        {
            std::cout << m << ' ';
        }
        std::cout << "\nTint : " << m_Tint << std::endl;
        std::cout << "Position : " << m_Position << std::endl;
    }

    auto Vegetation::ShowCount() -> void
    {
        std::cout << "Total objects created: " << m_Count << std::endl;
    }
}
