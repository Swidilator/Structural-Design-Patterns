//
// Created by Kyle on 2024/09/28.
//
module;
#include <vector>
#include <string>
#include <string_view>

export module flyweight.flyweight_assets.Vegetation;

import flyweight.flyweight_assets.Model;


namespace flyweight::flyweight_assets {
    export class VegetationData {
        std::vector<int> m_MeshData;
        const char *m_Texture{};

    public:
        VegetationData();

        auto GetTexture() const -> const char *;

        auto GetMeshData() const -> const std::vector<int> &;
    };


    export class Vegetation
            : public Model {
        inline static int m_Count{};
        VegetationData *m_pVegData{};
        std::string m_Tint{};

    public:
        Vegetation(std::string_view tint, VegetationData *p);

        auto Render(Position3D position) -> void override;

        static auto ShowCount() -> void;
    };
}
