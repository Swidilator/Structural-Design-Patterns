//
// Created by Kyle on 2024/09/28.
//
module;
#include <iostream>

module flyweight.flyweight_assets.Vegetation;

namespace flyweight::flyweight_assets {
    VegetationData::VegetationData() {
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

    auto VegetationData::GetTexture() const -> const char * {
        return m_Texture;
    }

    auto VegetationData::GetMeshData() const -> const std::vector<int> & {
        return m_MeshData;
    }

    Vegetation::Vegetation(std::string_view tint, VegetationData *p)
        : m_Tint{tint}, m_pVegData{p} {
        ++m_Count;
    }

    void Vegetation::Render(Position3D position) {
        std::cout << m_pVegData->GetTexture();
        std::cout << "Mesh: ";
        for (auto m: m_pVegData->GetMeshData()) {
            std::cout << m << ' ';
        }
        std::cout << "\nTint : " << m_Tint << std::endl;
        std::cout << "Position : " << position << std::endl;
    }


    auto Vegetation::ShowCount() -> void {
        std::cout << "Total objects created: " << m_Count << std::endl;
    }
}
