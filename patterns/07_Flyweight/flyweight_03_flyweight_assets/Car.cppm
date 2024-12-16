//
// Created by Kyle on 2024/10/01.
//
module;
#include <vector>

export module flyweight.flyweight_assets.Car;

import flyweight.flyweight_assets.Model;

namespace flyweight::flyweight_assets {
    export class Car
        : public Model
    {
        std::vector<int> m_MeshData{};
        const char* m_pTexture{};
        Position3D m_Position{};

    public:
        Car(const std::vector<int>& m_mesh_data, const char* m_p_texture, const Position3D& m_position)
            : m_MeshData(m_mesh_data),
              m_pTexture(m_p_texture),
              m_Position(m_position)
        {
        }

        auto Render() -> void override;
    };
}