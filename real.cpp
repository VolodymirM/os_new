#include "real.hpp"

VirtualMachine::VirtualMachine() {
    initRegisters();
    memory = new VirtualMemory();
}

Real::Real() {
    initRegisters();
    memory = new RealMemory();
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

void Real::initRegisters() {
    SP = 0;
    PC = 0;

    for (int i = 0; i < 6; ++i)
        SF[i] = 0;

    PTR = Word();
    MODE = 0;
    PI = 0;
    SI = 0;
    TI = 0;
}

void Real::printRegisters() {
    std::cout << "SP: " << SP;
    std::cout << " PC: " << PC;
    std::cout << " SF: ";
    for (int i = 0; i < 6; ++i)
        std::cout << SF[i];
    std::cout << " PTR: " << PTR.getWordAsHex();
    std::cout << " MODE: " << MODE;
    std::cout << " PI: " << PI;
    std::cout << " SI: " << SI;
    std::cout << " TI: " << TI << "\n";
}

void VirtualMachine::printUserMemory() { memory->printUserMemory(); }
void VirtualMachine::printUserMemory(const int64_t address) { memory->printUserMemory(address); }
void VirtualMachine::printUserMemory(const std::string addressHex) { memory->printUserMemory(addressHex); }
void Real::printSupervisorMemory() { memory->printSupervisorMemory(); }
void Real::printSupervisorMemory(const int64_t address) { memory->printSupervisorMemory(address); }
void Real::printSupervisorMemory(const std::string addressHex) { memory->printSupervisorMemory(addressHex); }