#include "real.hpp"

void ChannelDevice::makeOperation() {
    // TODO: implement channel device operations
}

RealMachine::RealMachine()
    : memory(new RealMemory()),
    channelsDevice(this),
    pagingMechanism(this) {
    initRegisters();
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

void RealMachine::printSupervisorMemory() { memory->printSupervisorMemory(); }
void RealMachine::printSupervisorMemory(const int64_t address) { memory->printSupervisorMemory(address); }
void RealMachine::printSupervisorMemory(const std::string addressHex) { memory->printSupervisorMemory(addressHex); }

VirtualMachine* RealMachine::getConnectedVM(const std::string vmName) {
    if (connectedVMs.find(vmName) != connectedVMs.end())
        return connectedVMs[vmName];
    else
        return nullptr;
}