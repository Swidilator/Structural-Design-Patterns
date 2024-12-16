//
// Created by Kyle on 2024/03/03.
//

module;

export module adapter.basic_example.basic_classes;

namespace adapter::basic_example
{
    export class Target
    {
    public:
        virtual auto Request() -> void = 0;
        virtual ~Target() = default;
    };

    export class Adaptee
    {
    public:
        auto SpecificRequest() -> void;
    };

    export class ObjectAdapter
        : public Target
    {
        Adaptee m_Adaptee;

    public:
        auto Request() -> void override;
    };

    export class ClassAdapter
        : public Target, public Adaptee
    {
        //Adaptee m_Adaptee;

    public:
        auto Request() -> void override;
    };


    export auto client(Target* pTarget) -> void
    {
        pTarget->Request();
    }


}
