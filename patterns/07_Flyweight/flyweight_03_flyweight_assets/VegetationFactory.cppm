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


namespace flyweight::flyweight_assets {
    using VegetationPtr = std::shared_ptr<Vegetation>;

    export class VegetationFactory {
        std::unordered_map<std::string_view, VegetationPtr> m_Flyweights{};
        VegetationData *m_pVegData{};

    public:
        VegetationFactory(VegetationData *mPVegData)
            : m_pVegData{mPVegData} {
        }

        auto GetVegetation(const std::string_view &tint) -> VegetationPtr;
    };
}
