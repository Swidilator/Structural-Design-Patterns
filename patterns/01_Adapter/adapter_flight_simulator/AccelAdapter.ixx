//
// Created by Kyle on 2024/03/08.
//

module;

export module adapter.flight_simulator.AccelAdapter;

import adapter.flight_simulator.Input;
import adapter.flight_simulator.Accelerometer;


namespace adapter::flight_simulator
{
    export class AccelObjectAdapter : public Input
    {
        Accelerometer m_Accel;

    public:
        AccelObjectAdapter()
            : m_Accel{}
        {
        }

        auto Down() -> bool override
        {
            return m_Accel.GetVerticalAxis() < 0;
        }

        auto Left() -> bool override
        {
            return m_Accel.GetHorizontalAxis() < 0;
        }

        auto Right() -> bool override
        {
            return m_Accel.GetHorizontalAxis() > 0;
        }

        auto Up() -> bool override
        {
            return m_Accel.GetVerticalAxis() > 0;
        }
    };

    export class AccelClassAdapter : public Input, public Accelerometer
    {
    public:
        auto Down() -> bool override
        {
            return GetVerticalAxis() < 0;
        }

        auto Left() -> bool override
        {
            return GetHorizontalAxis() < 0;
        }

        auto Right() -> bool override
        {
            return GetHorizontalAxis() > 0;
        }

        auto Up() -> bool override
        {
            return GetVerticalAxis() > 0;
        }
    };
}
