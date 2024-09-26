//
// Created by kyle on 2024/09/23.
//

import bridge.basic_example.main;
import bridge.shapes.main;
import bridge.shapes_bridge.main;
import bridge.shared_implementation.main;
import bridge.PIMPL.main;

auto main(int argc, char *argv[]) -> int {
    //bridge::basic_example::main_basic_example();
    //bridge::shapes::main_shapes();
    //bridge::shapes_bridge::main_shapes_bridge();
    //bridge::shared_implementation::main_shared_implementation();
    bridge::PIMPL::main_PIMPL();
    return 0;
}
