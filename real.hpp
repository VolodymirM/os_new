#ifndef REAL_HPP
#define REAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"

class Real {
private:
    char SP[4];
    char PC[4];
    bool SF[6];
    Word PTR;
    bool MODE;
    bool PI;
    unsigned SI;
    bool TI;
    RealMemory* memory;

    void initRegisters();

public:
    Real();
    void printUserMemory();
    void printUserMemory(const int64_t address);
    void printUserMemory(const std::string addressHex);
    void printSupervisorMemory();
    void printSupervisorMemory(const int64_t address);
    void printSupervisorMemory(const std::string addressHex);

};

#endif