target_sources(01_Adapter PUBLIC
        FILE_SET adapter_flight_simulator_modules
        TYPE CXX_MODULES
        FILES main_adapter_flight_simulator.ixx
        Game.ixx
        Input.ixx
        Keyboard.ixx
        Accelerometer.ixx
        AccelAdapter.ixx
)