//
// Created by Kyle on 2024/07/05.
//
module;
#include <objbase.h>

export module proxy.remote_proxy.IAnimate;

namespace proxy::remote_proxy
{
    export class IAnimate
    {
    public:
        virtual HRESULT SetImage(unsigned char image) = 0;
        virtual HRESULT Animate(int duration) = 0;
        virtual ~IAnimate() = default;
    };
}
Tana Core