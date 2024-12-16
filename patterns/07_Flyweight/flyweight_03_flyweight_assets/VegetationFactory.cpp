//
// Created by kyle on 2024/09/29.
//
module;
#include <unordered_map>
#include <string_view>
#include <memory>


module flyweight.flyweight_assets.VegetationFactory;

import flyweight.flyweight_assets.Vegetation;

namespace flyweight::flyweight_assets {
    auto VegetationFactory::GetVegetation(const std::string_view &tint) -> VegetationPtr {
        auto found = m_Flyweights.contains(tint);
        if (!found) {
            m_Flyweights[tint] = std::make_shared<Vegetation>(tint, m_pVegData);
        }
        return m_Flyweights[tint];
    }

    auto VegetationFactory::GetCar(const std::vector<int>& m_mesh_data, const char* m_p_texture,
        const Position3D& m_position) -> std::shared_ptr<Car>
    {
        return std::make_shared<Car>(m_mesh_data, m_p_texture, m_position);
    }
}
