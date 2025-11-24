#ifndef REALCOMPONENTS_HPP
#define REALCOMPONENTS_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"

class VirtualMemory {
protected:
    std::unordered_map<std::string, Block*> user_memory;

    bool isWordEmpty(Word* word);
public:
    VirtualMemory();
    void printUserMemory();
    void printUserMemory(const int64_t address);
    void printUserMemory(const std::string addressHex);
    Block& getBlock(const std::string address);
    Block& getBlock(const int index);
    virtual Word& getWord(const std::string address, size_t index);
    virtual void setWord(const std::string address, size_t index, Word* word);
    virtual Word& getWord(const int index, size_t wordIndex);
    virtual void setWord(const int index, size_t wordIndex, Word* word);
    
};

class RealMemory : public VirtualMemory {
private:
    std::unordered_map<std::string, Word*> supervisor_memory;

public:
    RealMemory();
    void printSupervisorMemory();
    void printSupervisorMemory(const int64_t address);
    void printSupervisorMemory(const std::string addressHex);
    Word& getWord(const std::string address, size_t index) override;
    void setWord(const std::string address, size_t index, Word* word) override;
    Word& getWord(const int index, size_t wordIndex) override;
    void setWord(const int index, size_t wordIndex, Word* word) override;
    Word& getSupervisorWord(const std::string address);
    void setSupervisorWord(const std::string address, Word* word);
    Word& getSupervisorWord(const int index);
    void setSupervisorWord(const int index, Word* word);

};

#endif