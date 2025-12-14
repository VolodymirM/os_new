#include "memory.hpp"

UserMemory::UserMemory() {
    for (int i = 0; i < USER_MEMORY_SIZE; ++i)
        for (int j = 0; j < BLOCK_SIZE; ++j)
            words[i][j] = Word();
}

void UserMemory::printBlock(const int index) {
    if (index < 0 || index >= USER_MEMORY_SIZE) {
        std::cerr << "Invalid block index in UserMemory::printBlock\n";
        return;
    }
    std::cout << converter.numToHex(index) << " "; 
    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        Word word = words[index][i];
        if (word.getWordAsHex() == "0")
            std::cout << "------ ";
        else
            std::cout << word.getWord() << " ";
    }
    std::cout << "\n";
}

Word& UserMemory::getWord(const int index, size_t wordIndex) {
    if (index < 0 || index >= USER_MEMORY_SIZE || wordIndex >= BLOCK_SIZE)
        throw std::out_of_range("Invalid index in UserMemory::getWord");
    return words[index][wordIndex];
}

void UserMemory::setWord(const int index, size_t wordIndex, Word* word) {
    if (index < 0 || index >= USER_MEMORY_SIZE || wordIndex >= BLOCK_SIZE)
        throw std::out_of_range("Invalid index in UserMemory::setWord");
    words[index][wordIndex] = *word;
}

SupervisorMemory::SupervisorMemory() {
    for (int i = 0; i < SUPERVISOR_MEMORY_SIZE; ++i)
        for (int j = 0; j < BLOCK_SIZE; ++j)
            words[i][j] = Word();
}

void SupervisorMemory::printBlock(const int index) {
    if (index < 256 || index >= SUPERVISOR_MEMORY_SIZE + 256) {
        std::cerr << "Invalid block index in SupervisorMemory::printBlock\n";
        return;
    }
    std::cout << converter.numToHex(index) << " "; 
    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        Word word = words[index - 256][i];
        if (word.getWordAsHex() == "0")
            std::cout << "------ ";
        else
            std::cout << word.getWord() << " ";
    }
    std::cout << "\n";
}

Word& SupervisorMemory::getWord(const int index, size_t wordIndex) {
    if (index < 256 || index >= SUPERVISOR_MEMORY_SIZE + 256 || wordIndex >= BLOCK_SIZE)
        throw std::out_of_range("Invalid index in SupervisorMemory::getWord");
    return words[index - 256][wordIndex];
}

void SupervisorMemory::setWord(const int index, size_t wordIndex, Word* word) {
    if (index < 256 || index >= SUPERVISOR_MEMORY_SIZE + 256 || wordIndex >= BLOCK_SIZE)
        throw std::out_of_range("Invalid index in SupervisorMemory::setWord");
    words[index - 256][wordIndex] = *word;
}

Memory::Memory() : userMemory(), supervisorMemory() {}

Word& Memory::getWord(const int index, size_t wordIndex) {
    if (index >= 0 && index < 256)
        return userMemory.getWord(index, wordIndex);
    else if (index >= 256 && index < 512)
        return supervisorMemory.getWord(index, wordIndex);
    else
        throw std::out_of_range("Invalid index in Memory::getWord");
}

void Memory::setWord(const int index, size_t wordIndex, Word* word) {
    if (index >= 0 && index < 256)
        userMemory.setWord(index, wordIndex, word);
    else if (index >= 256 && index < 512)
        supervisorMemory.setWord(index, wordIndex, word);
    else
        throw std::out_of_range("Invalid index in Memory::setWord");
}

void Memory::printBlock(const int index) {
    if (index >= 0 && index < 256)
        printUserBlock(index);
    else if (index >= 256 && index < 512)
        printSupervisorBlock(index);
    else
        std::cerr << "Invalid block index in Memory::printBlock\n";
}

void Memory::printUserBlock(const int index) { userMemory.printBlock(index); }
void Memory::printSupervisorBlock(const int index) { supervisorMemory.printBlock(index); }
UserMemory* Memory::getUserMemoryAddress() { return &userMemory; }
