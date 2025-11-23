#ifndef REALCOMPONENTS_HPP
#define REALCOMPONENTS_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"

class Memory {
private:
    std::unordered_map<std::string, Block*> user_memory;
    std::unordered_map<std::string, Word*> supervisor_memory;

public:
    Memory();
    Block& getBlock(const std::string address);
    Block& getBlock(const int index);
    Word& getWord(const std::string address, size_t index);
    void setWord(const std::string address, size_t index, Word* word);
    Word& getWord(const int index, size_t wordIndex);
    void setWord(const int index, size_t wordIndex, Word* word);
    Word& getSupervisorWord(const std::string address);
    void setSupervisorWord(const std::string address, Word* word);
    Word& getSupervisorWord(const int index);
    void setSupervisorWord(const int index, Word* word);

};

#endif