//
// Created by kyle on 2024/09/29.
//
module;
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

export module flyweight.flyweight_assets.VegetationFactory;

import flyweight.flyweight_assets.Model;
import flyweight.flyweight_assets.Vegetation;
import flyweight.flyweight_assets.Vegetation;
import flyweight.flyweight_assets.Car;


namespace flyweight::flyweight_assets {
    export using VegetationPtr = std::shared_ptr<Model>;

    export class VegetationFactory {
        std::unordered_map<std::string_view, VegetationPtr> m_Flyweights{};
        VegetationData *m_pVegData{};

    public:
        VegetationFactory(VegetationData *mPVegData)
            : m_pVegData{mPVegData} {
        }

        auto GetVegetation(const std::string_view &tint) -> VegetationPtr;
        auto GetCar(const std::vector<int>& m_mesh_data, const char* m_p_texture, const Position3D& m_position) -> std::shared_ptr<Car>;
    };
}
