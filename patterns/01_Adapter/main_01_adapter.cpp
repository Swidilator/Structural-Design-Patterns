#include <iostream>

import adapter.basic_example.main;
//import adapter.flight_simulator.main;

int main()
{
    adapter::basic_example::main_adapter_basic();
    //adapter::flight_simulator::main_adapter_flight_simulator();
}

/* OBJECT ADAPTER
 *
 * Advantages:
 * One adapter can work with multiple classes (even subclasses of adaptee)
 * Can always adapt to an existing class
 *
 * Disadvantages:
 * Cannot override adaptee's behavior
 * Methods are invoked through pointer indirection
 *
 *
 * CLASS ADAPTER
 *
 * Advantages:
 * Method calls are direct as they're inherited (no pointer indirection)
 * Can override adaptee's behaviour
 *
 * Disadvantes:
 * Won't work if the adaptee is final or sealed
 * Uses multiple class inheritance (may not be possible in all languages)
 * Won't work with subclasses of adaptees
 *
 *
 * WHEN TO USE
 * You want to use an existing class, and it had an incompatible interface
 * You need to use classes from an existing hierarchy, buy they have an incompatible interface
 * You need to reuse an existing class with incompatible interface, but want to modify some behavior
 */
