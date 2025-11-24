#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "memory.hpp"

// Virtual Machine and its components
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

#endif