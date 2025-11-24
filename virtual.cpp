#include "virtual.hpp"

VirtualMachine::VirtualMachine() {
    initRegisters();
    memory = new VirtualMemory();
}

void VirtualMachine::printRegisters() {
    std::cout << "SP: " << SP;
    std::cout << " PC: " << PC;
    std::cout << " SF: ";
    for (int i = 0; i < 6; ++i)
        std::cout << SF[i];
    std::cout << "\n";
}

void VirtualMachine::initRegisters() {
    SP = 0;
    PC = 0;

    for (int i = 0; i < 6; ++i)
        SF[i] = 0;
}

void VirtualMachine::printUserMemory() { memory->printUserMemory(); }
void VirtualMachine::printUserMemory(const int64_t address) { memory->printUserMemory(address); }
void VirtualMachine::printUserMemory(const std::string addressHex) { memory->printUserMemory(addressHex); }