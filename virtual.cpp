#include "virtual.hpp"

VirtualMachine::VirtualMachine(bool sf[6], unsigned& sp, unsigned& pc, UserMemory& memory) {
    SF = sf;
    SP = &sp;
    PC = &pc;
    this->memory = &memory;
}

void VirtualMachine::printRegisters() {
    std::cout << "SP: " << *SP;
    std::cout << " PC: " << *PC;
    std::cout << " SF: ";
    for (int i = 0; i < 6; ++i)
        std::cout << SF[i];
    std::cout << "\n";
}