#ifndef REALCOMPONENTS_HPP
#define REALCOMPONENTS_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"

class UserMemory {
private:
    Word words[USER_MEMORY_SIZE][BLOCK_SIZE];

public:
    UserMemory();
    void printBlock(const int index);
    Word& getWord(const int index, size_t wordIndex);
    void setWord(const int index, size_t wordIndex, Word* word);
};

class SupervisorMemory {
private:
    Word words[SUPERVISOR_MEMORY_SIZE][BLOCK_SIZE];

public:
    SupervisorMemory();
    void printBlock(const int index);
    Word& getWord(const int index, size_t wordIndex);
    void setWord(const int index, size_t wordIndex, Word* word);
};

class Memory {
private:
    UserMemory userMemory;
    SupervisorMemory supervisorMemory;
    void printUserBlock(const int index);
    void printSupervisorBlock(const int index);

public:
    Memory();
    Word& getWord(const int index, size_t wordIndex);
    void setWord(const int index, size_t wordIndex, Word* word);
    void printBlock(const int index);
    UserMemory* getUserMemoryAddress();
    
};

#endif