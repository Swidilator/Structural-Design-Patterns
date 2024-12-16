//
// Created by kyle on 2024/09/20.
//

module;
#include <memory>
#include <iostream>
#include <vector>

export module flyweight.flyweight_assets.main;

import flyweight.flyweight_assets.Model;
import flyweight.flyweight_assets.Vegetation;
import flyweight.flyweight_assets.VegetationFactory;


namespace flyweight::flyweight_assets
{
    export auto main_flyweight_assets() -> void
    {
        std::vector<VegetationPtr> m_Trees{};
        VegetationData data{};
        VegetationFactory factory{&data};
        for (int i = 0; i < 15; ++i)
        {
            if (i < 5)
            {
                m_Trees.push_back(factory.GetVegetation("Green"));
                //m_Trees.push_back(std::make_shared<Vegetation>("Green", Position3D{i * 10, i * 10, i * 10}));
            }
            else if (i > 5 && i <= 10)
            {
                m_Trees.push_back(factory.GetVegetation("Dark Green"));
                //m_Trees.push_back(std::make_shared<Vegetation>("Dark Green", Position3D{i + 10, i + 10, i + 10}));
            }
            else
            {
                m_Trees.push_back(factory.GetVegetation("Light Green"));
                //m_Trees.push_back(
                //    std::make_shared<Vegetation>("Light Green", Position3D{i * 10 + 10, i * 10 + 10, i * 10 + 10}));
            }
        }
        for (int i = 0; i < m_Trees.size(); ++i)
        {
            if (i < 5)
            {
                m_Trees[i]->Render({i * 10, i * 10, i * 10});
            }
            else if (i > 5 && i <= 10)
            {
                m_Trees[i]->Render({i + 10, i + 10, i + 10});
            }
            else
            {
                m_Trees[i]->Render({i * 10 + 10, i * 10 + 10, i * 10 + 10});
            }
        }
        Vegetation::ShowCount();

        auto c1 = factory.GetCar({1,2,3,4}, "Car texture", {10, 10, 10});
    }
}
