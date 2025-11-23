#include "machines.hpp"

VirtualMachine::VirtualMachine() {
    initRegisters();
    memory = new VirtualMemory();
}

ChannelDevice::ChannelDevice(RealMemory* memory) : memory(memory) {}

void ChannelDevice::makeOperation() {
    // TODO: implement channel device operations
}

RealMachine::RealMachine()
    : memory(new RealMemory()),
    channelsDevice(memory),
    pagingMechanism() {
    initRegisters();
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

void RealMachine::initRegisters() {
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

void RealMachine::printRegisters() {
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
void RealMachine::printSupervisorMemory() { memory->printSupervisorMemory(); }
void RealMachine::printSupervisorMemory(const int64_t address) { memory->printSupervisorMemory(address); }
void RealMachine::printSupervisorMemory(const std::string addressHex) { memory->printSupervisorMemory(addressHex); }