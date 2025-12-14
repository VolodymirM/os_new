#ifndef REAL_HPP
#define REAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"
#include "virtual.hpp"

// Real Machine and its components
class RealMachine;

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

class RealMachine { // TODO: CPU struct
private:
    // Registers
    bool SF[6]; // 6 flags
    unsigned PC;
    unsigned SP; // 4 bytes
    Word PTR;
    bool MODE; // 0 - user mode, 1 - supervisor mode
    bool PI;
    unsigned SI;
    bool TI;

    // Other components
    Memory memory; 
    ChannelDevice channelsDevice;
    PagingMechanism pagingMechanism;
    
    void initRegisters();
    void createSwappingFile();

public: // TODO: print channel device registers
    RealMachine();
    void makeOperation(); // TODO: implement
    void printRegisters(); // Register methods
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
    void setSF(size_t index, bool value) { SF[index] = value; }
    bool getSF(size_t index) const { return SF[index]; }
    void setWord(const size_t blockIndex, const size_t wordIndex, Word* word) { memory.setWord(blockIndex, wordIndex, word); }
    void printMemoryBlock(const size_t block) { memory.printBlock(block); }

};

#endif