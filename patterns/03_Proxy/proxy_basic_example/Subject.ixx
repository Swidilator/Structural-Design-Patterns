//
// Created by Kyle on 2024/04/07.
//

export module proxy.basic_example.Subject;

namespace proxy::basic_example
{
    export class Subject
    {
    public:
        virtual void Request() = 0;
        virtual ~Subject() = default;
    };
}
