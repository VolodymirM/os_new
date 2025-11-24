#ifndef REAL_HPP
#define REAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"

// Virtual Machine
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
    Word& getWord(const std::string address, size_t index) { return memory->getWord(address, index); }
    void setWord(const std::string address, size_t index, Word* word) { memory->setWord(address, index, word); }
    Word& getWord(const int index, size_t wordIndex) { return memory->getWord(index, wordIndex); }
    void setWord(const int index, size_t wordIndex, Word* word) { memory->setWord(index, wordIndex, word); }

};

// Real Machine and its components
class ChannelDevice {
private:
    Word SB; // source block
    Word DB; // destination block
    unsigned ST; // source type
    unsigned DT; // destination type
    size_t offset;
    unsigned count;

    RealMemory* memory;
public:
    ChannelDevice(RealMemory* memory) : memory(memory) {};
    void setSB(const Word& sb) { SB = sb; }
    void setDB(const Word& db) { DB = db; }
    void setST(unsigned st) { ST = st; }
    void setDT(unsigned dt) { DT = dt; }
    void setOffset(size_t off) { offset = off; }
    void setCount(unsigned cnt) { count = cnt; }
    void makeOperation();

};

class PagingMechanism { // TODO: implement
private:

public:
    PagingMechanism() {}

};

class RealMachine : public VirtualMachine {
private:
    // Registers
    unsigned SP; // 4 bytes
    unsigned PC;
    Word PTR;
    bool MODE; // 0 - user mode, 1 - supervisor mode
    bool PI;
    unsigned SI;
    bool TI;

    // Other components
    RealMemory* memory;
    ChannelDevice channelsDevice;
    PagingMechanism pagingMechanism;
    
    void initRegisters() override;

public:
    RealMachine();
    void printRegisters() override;
    void printSupervisorMemory();
    void printSupervisorMemory(const int64_t address);
    void printSupervisorMemory(const std::string addressHex);
    Word& getSupervisorWord(const std::string address) { return memory->getSupervisorWord(address); }
    void setSupervisorWord(const std::string address, Word* word) { memory->setSupervisorWord(address, word); }
    Word& getSupervisorWord(const int index) { return memory->getSupervisorWord(index); }
    void setSupervisorWord(const int index, Word* word) { memory->setSupervisorWord(index, word); }

};

#endif