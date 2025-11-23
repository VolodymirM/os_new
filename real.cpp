#include "real.hpp"

Real::Real() {
    initRegisters();
    memory = new RealMemory();
}

void Real::initRegisters() {
    for (int i = 0; i < 4; ++i) {
        SP[i] = 0;
        PC[i] = 0;
        SF[i] = 0;
    }

    for (int i = 4; i < 6; ++i)
        SF[i] = 0;

    PTR = Word();
    MODE = 0;
    PI = 0;
    SI = 0;
    TI = 0;
}

void Real::printUserMemory() { memory->printUserMemory(); }
void Real::printUserMemory(const int64_t address) { memory->printUserMemory(address); }
void Real::printUserMemory(const std::string addressHex) { memory->printUserMemory(addressHex); }
void Real::printSupervisorMemory() { memory->printSupervisorMemory(); }
void Real::printSupervisorMemory(const int64_t address) { memory->printSupervisorMemory(address); }
void Real::printSupervisorMemory(const std::string addressHex) { memory->printSupervisorMemory(addressHex); }