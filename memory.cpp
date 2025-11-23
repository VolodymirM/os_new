#include "memory.hpp"

bool VirtualMemory::isWordEmpty(Word* word) {
    const char* letters = word->getWord();
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (letters[i] != '\0')  // NULL character here (in our documentation it is '-' - change if needed)
            return false;
    }
    return true;
}

VirtualMemory::VirtualMemory() {
    for (int64_t index = 0; index < USER_MEMORY_SIZE; ++index)
            user_memory[converter.numToHex(index)] = new Block(index);
}

RealMemory::RealMemory() {
    for (int64_t index = 0; index < USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE; ++index) {
        if (index < USER_MEMORY_SIZE)
            user_memory[converter.numToHex(index)] = new Block(index);
        else
            supervisor_memory[converter.numToHex(index)] = new Word();
    }
}

void VirtualMemory::printUserMemory() {
    for (int64_t index = 0; index < USER_MEMORY_SIZE; ++index) {
        std::cout << converter.numToHex(index) << ":";
        for (size_t i = 0; i < BLOCK_SIZE; ++i) {
            Block& block = *user_memory[converter.numToHex(index)];
            Word& word = block.getWord(i);
            if (!isWordEmpty(&word)) 
                std::cout << word.getWord() << " ";
            else
                std::cout << "------ ";
        }
        std::cout << "\n";
    }
}

void VirtualMemory::printUserMemory(const int64_t address) {
    if (address < 0 || address >= USER_MEMORY_SIZE) {
        std::cout << "Invalid address in printUserMemory(int64_t)\n";
        return;
    }
    std::cout << converter.numToHex(address) << ":";
    Block& block = *user_memory[converter.numToHex(address)];
    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        Word& word = block.getWord(i);
        if (!isWordEmpty(&word)) 
            std::cout << word.getWord() << " ";
        else
            std::cout << "------ ";
    }
    std::cout << "\n";
}

void VirtualMemory::printUserMemory(const std::string addressHex) {
    std::string trimmedAddress = addressHex;
    trimmedAddress.erase(0, trimmedAddress.find_first_not_of('0'));
    std::transform(trimmedAddress.begin(), trimmedAddress.end(), trimmedAddress.begin(), ::tolower);
    if (trimmedAddress.empty() || user_memory.find(trimmedAddress) == user_memory.end()) {
        std::cout << "Invalid address in printUserMemory(string)\n";
        return;
    }
    std::cout << trimmedAddress << ":";
    Block& block = *user_memory[trimmedAddress];
    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        Word& word = block.getWord(i);
        if (!isWordEmpty(&word)) 
            std::cout << word.getWord() << " ";
        else
            std::cout << "------ ";
    }
    std::cout << "\n";
}

void RealMemory::printSupervisorMemory() {
    for (int64_t index = USER_MEMORY_SIZE; index < USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE; ++index) {
        std::cout << converter.numToHex(index) << " ";
        if (!isWordEmpty(supervisor_memory[converter.numToHex(index)])) 
            std::cout << supervisor_memory[converter.numToHex(index)]->getWord() << "\n";
        else
            std::cout << "------\n";
    }
}

void RealMemory::printSupervisorMemory(const int64_t address) {
    if (address < USER_MEMORY_SIZE || address >= USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE) {
        std::cout << "Invalid address in printSupervisorMemory(int64_t)\n";
        return;
    }
    std::cout << converter.numToHex(address) << " ";
    if (!isWordEmpty(supervisor_memory[converter.numToHex(address)])) 
        std::cout << supervisor_memory[converter.numToHex(address)]->getWord() << "\n";
    else
        std::cout << "------\n";
}

void RealMemory::printSupervisorMemory(const std::string addressHex) {
    std::string trimmedAddress = addressHex;
    trimmedAddress.erase(0, trimmedAddress.find_first_not_of('0'));
    std::transform(trimmedAddress.begin(), trimmedAddress.end(), trimmedAddress.begin(), ::tolower);
    if (trimmedAddress.empty() || supervisor_memory.find(trimmedAddress) == supervisor_memory.end()) {
        std::cout << "Invalid address in printSupervisorMemory(string)\n";
        return;
    }
    std::cout << trimmedAddress << " ";
    if (!isWordEmpty(supervisor_memory[trimmedAddress])) 
        std::cout << supervisor_memory[trimmedAddress]->getWord() << "\n";
    else
        std::cout << "------\n";
}

Block& VirtualMemory::getBlock(const std::string address) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in getBlock(string)");
    return *user_memory[address];
}

Block& VirtualMemory::getBlock(const int index) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getBlock(int)");
    return *user_memory[converter.numToHex(index)];
}

Word& VirtualMemory::getWord(const std::string address, size_t index) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in getWord(string, size_t)");
    if (index > BLOCK_SIZE || index < 0)
        throw std::out_of_range("Invalid index in getWord(string, size_t)");
    return user_memory[address]->getWord(index);
}

void VirtualMemory::setWord(const std::string address, size_t index, Word* word) {
    if (address.empty() || user_memory.find(address) == user_memory.end())
        throw std::out_of_range("Invalid address in setWord(string, size_t, Word*)");
    if (index > BLOCK_SIZE || index < 0)
        throw std::out_of_range("Invalid index in setWord(string, size_t, Word*)");
    user_memory[address]->getWord(index) = *word;
}

Word& VirtualMemory::getWord(const int index, size_t wordIndex) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getWord(int, size_t)");
    if (wordIndex > BLOCK_SIZE || wordIndex < 0)
        throw std::out_of_range("Invalid wordIndex in getWord(int, size_t)");
    return user_memory[converter.numToHex(index)]->getWord(wordIndex);
}

void VirtualMemory::setWord(const int index, size_t wordIndex, Word* word) {
    if (index < 0 || index >= USER_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in setWord(int, size_t, Word*)");
    if (wordIndex > BLOCK_SIZE || wordIndex < 0)
        throw std::out_of_range("Invalid wordIndex in setWord(int, size_t, Word*)");
    user_memory[converter.numToHex(index)]->getWord(wordIndex) = *word;
}

Word& RealMemory::getSupervisorWord(const std::string address) {
    if (address.empty() || supervisor_memory.find(address) == supervisor_memory.end())
        throw std::out_of_range("Invalid address in getSupervisorWord(string)");
    return *supervisor_memory[address];
}

void RealMemory::setSupervisorWord(const std::string address, Word* word) {
    if (address.empty() || supervisor_memory.find(address) == supervisor_memory.end())
        throw std::out_of_range("Invalid address in setSupervisorWord(string, Word*)");
    supervisor_memory[address] = word;
}


Word& RealMemory::getSupervisorWord(const int index) {
    if (index < USER_MEMORY_SIZE || index >= USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in getSupervisorWord(int)");
    return *supervisor_memory[converter.numToHex(index)];
}


void RealMemory::setSupervisorWord(const int index, Word* word) {
    if (index < USER_MEMORY_SIZE || index >= USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE)
        throw std::out_of_range("Invalid index in setSupervisorWord(int, Word*)");
    supervisor_memory[converter.numToHex(index)] = word;
}