//
// Created by Kyle on 2024/07/05.
//
module;
#include <iostream>
#include <objbase.h>

export module proxy.remote_proxy.Sprite;

import proxy.remote_proxy.IAnimate;

namespace proxy::remote_proxy
{
    export class Sprite
        : public IAnimate
    {
        unsigned char m_Image;

    public:
        HRESULT Animate(int duration) override {
            for (int i = 0; i < duration; ++i) {
                std::cout << m_Image;
                Sleep(1000);
            }

            return S_OK;
        }

        HRESULT SetImage(unsigned char image) override {
            m_Image = image;
            return S_OK;
        }
    };
}
