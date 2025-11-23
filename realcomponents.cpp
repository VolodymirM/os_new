#include "realcomponents.hpp"

Memory::Memory() {
    for (int64_t index = 0; index < USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE; ++index) {
        if (index < USER_MEMORY_SIZE)
            user_memory[converter.numToHex(index)] = new Block();
        else
            supervisor_memory[converter.numToHex(index)] = new Word();
    }
}

Block& Memory::getBlock(const std::string address) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in getBlock(string)");
    return *user_memory[address];
}

Block& Memory::getBlock(const int index) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getBlock(int)");
    return *user_memory[converter.numToHex(index)];
}

Word& Memory::getWord(const std::string address, size_t index) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in getWord(string, size_t)");
    return user_memory[address]->getWord(index);
}

void Memory::setWord(const std::string address, size_t index, Word* word) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in setWord(string, size_t, Word*)");
    user_memory[address]->getWord(index) = *word;
}

Word& Memory::getWord(const int index, size_t wordIndex) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getWord(int, size_t)");
    return user_memory[converter.numToHex(index)]->getWord(wordIndex);
}

void Memory::setWord(const int index, size_t wordIndex, Word* word) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in setWord(int, size_t, Word*)");
    user_memory[converter.numToHex(index)]->getWord(wordIndex) = *word;
}

Word& Memory::getSupervisorWord(const std::string address) {
    if (address.empty() || supervisor_memory.find(address) == supervisor_memory.end())
        throw std::out_of_range("Invalid address in getSupervisorWord(string)");
    return *supervisor_memory[address];
}

void Memory::setSupervisorWord(const std::string address, Word* word) {
    if (address.empty() || supervisor_memory.find(address) == supervisor_memory.end())
        throw std::out_of_range("Invalid address in setSupervisorWord(string, Word*)");
    supervisor_memory[address] = word;
}

Word& Memory::getSupervisorWord(const int index) {
    if (index < 0 || index < USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getSupervisorWord(int)");
    return *supervisor_memory[converter.numToHex(index)];
}

void Memory::setSupervisorWord(const int index, Word* word) {
    if (index < 0 || index < USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in setSupervisorWord(int, Word*)");
    supervisor_memory[converter.numToHex(index)] = word;
}