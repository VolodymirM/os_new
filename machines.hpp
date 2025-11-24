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
    virtual void printRegisters(); // Register methods
    void setSP(unsigned short sp) { SP = sp; }
    unsigned short getSP() const { return SP; }
    void setPC(unsigned short pc) { PC = pc; }
    unsigned short getPC() const { return PC; }
    const bool* getSF() const { return SF; }
    void setSF(const bool sf[6]) { for (int i = 0; i < 6; ++i) this->SF[i] = sf[i]; }
    void printUserMemory(); // Memory methods
    void printUserMemory(const int64_t address);
    void printUserMemory(const std::string addressHex);
    Word& getWord(const std::string address, size_t index) { return memory->getWord(address, index); }
    void setWord(const std::string address, size_t index, Word* word) { memory->setWord(address, index, word); }
    Word& getWord(const int index, size_t wordIndex) { return memory->getWord(index, wordIndex); }
    void setWord(const int index, size_t wordIndex, Word* word) { memory->setWord(index, wordIndex, word); }

};

class RealMachine;

// Real Machine and its components
class RealComponent {
protected:
    RealMachine* machine;
    
public:
    RealComponent(RealMachine* machine) : machine(machine) {}

};

class ChannelDevice : public RealComponent {
private:
    Word SB; // source block
    Word DB; // destination block
    unsigned ST; // source type
    unsigned DT; // destination type
    size_t offset;
    unsigned count;

public:
    ChannelDevice(RealMachine* machine) : RealComponent(machine) {};
    void setSB(const Word& sb) { SB = sb; }
    void setDB(const Word& db) { DB = db; }
    void setST(unsigned st) { ST = st; }
    void setDT(unsigned dt) { DT = dt; }
    void setOffset(size_t off) { offset = off; }
    void setCount(unsigned cnt) { count = cnt; }
    void makeOperation();

};

class PagingMechanism : public RealComponent { // TODO: implement
private:

public:
    PagingMechanism(RealMachine* machine) : RealComponent(machine) {}

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
    std::unordered_map<std::string, VirtualMachine* > connectedVMs;
    
    void initRegisters() override;

public:
    RealMachine();
    void printRegisters() override; // Register methods
    void setSP(unsigned sp) { SP = sp; }
    unsigned getSP() const { return SP; }
    void setPC(unsigned pc) { PC = pc; }
    unsigned getPC() const { return PC; }
    void setPTR(const Word& ptr) { PTR = ptr; }
    Word getPTR() const { return PTR; }
    void setMODE(bool mode) { MODE = mode; }
    bool getMODE() const { return MODE; }
    void setPI(bool pi) { PI = pi; }
    bool getPI() const { return PI; }
    void setSI(unsigned si) { SI = si; }
    unsigned getSI() const { return SI; }
    void setTI(bool ti) { TI = ti; }
    bool getTI() const { return TI; }
    void printSupervisorMemory(); // Memory methods
    void printSupervisorMemory(const int64_t address);
    void printSupervisorMemory(const std::string addressHex);
    Word& getSupervisorWord(const std::string address) { return memory->getSupervisorWord(address); }
    void setSupervisorWord(const std::string address, Word* word) { memory->setSupervisorWord(address, word); }
    Word& getSupervisorWord(const int index) { return memory->getSupervisorWord(index); }
    void setSupervisorWord(const int index, Word* word) { memory->setSupervisorWord(index, word); }
    void connectVM(const std::string vmName, VirtualMachine* vm) { connectedVMs[vmName] = vm; } // VM methods
    void disconnectVM(const std::string vmName) { connectedVMs.erase(vmName); }
    VirtualMachine* getConnectedVM(const std::string vmName);

};

#endif