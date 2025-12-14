#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"

// Virtual Machine and its components
class VirtualMachine {
private:
    bool* SF;
    unsigned* SP; // 4 bytes
    unsigned* PC;
    UserMemory* memory;

public:
    VirtualMachine(bool sf[6], unsigned& sp, unsigned& pc, UserMemory& memory);
    void printRegisters(); // Register methods
    const bool getSF(size_t index) const { return SF[index]; }
    void setSF(size_t index, bool value) { SF[index] = value; }
    void setSP(unsigned sp) { *SP = sp; }
    unsigned getSP() const { return *SP; }
    void setPC(unsigned pc) { *PC = pc; }
    unsigned getPC() const { return *PC; }
    void printMemoryBlock(const size_t block) { memory->printBlock(block); }
    void setWord(const size_t blockIndex, const size_t wordIndex, Word* word) { memory->setWord(blockIndex, wordIndex, word); }

};

#endif