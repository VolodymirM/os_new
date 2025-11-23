#ifndef REAL_HPP
#define REAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"

class VirtualMachine {
private:
    unsigned short SP; // 2 bytes
    unsigned short PC;
    VirtualMemory* memory;

protected:
    bool SF[6];

    virtual void initRegisters();

public:
    VirtualMachine();
    virtual void printRegisters();
    void printUserMemory();
    void printUserMemory(const int64_t address);
    void printUserMemory(const std::string addressHex);

};

class Real : public VirtualMachine {
private:
    unsigned SP; // 4 bytes
    unsigned PC;
    Word PTR;
    bool MODE; // 0 - user mode, 1 - supervisor mode
    bool PI;
    unsigned SI;
    bool TI;
    RealMemory* memory;

    void initRegisters() override;

public:
    Real();
    void printRegisters() override;
    void printSupervisorMemory();
    void printSupervisorMemory(const int64_t address);
    void printSupervisorMemory(const std::string addressHex);

};

#endif