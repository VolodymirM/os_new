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
    
    if (!word) {
        std::cerr << "Error: Null word pointer provided.\n";
        return;
    }

    words[index][wordIndex] = *word;
    delete word;
}

void UserMemory::setWord(const int index, size_t wordIndex, const char* word) {
    if (index < 0 || index >= USER_MEMORY_SIZE || wordIndex >= BLOCK_SIZE) {
        throw std::out_of_range("Invalid index in UserMemory::setWord");
    }

    if (!word) {
        std::cerr << "Error: Null word provided.\n";
        return;
    }

    unsigned wordSize = strlen(word);
    if (wordSize <= WORD_LENGTH)
        setWord(index, wordIndex, new Word(word));
    else {
        char extractedWord[WORD_LENGTH + 1] = {0};
        strncpy(extractedWord, word, WORD_LENGTH);
        setWord(index, wordIndex, new Word(extractedWord));
        size_t remainingSize = wordSize - WORD_LENGTH;
        char* remainingWord = new char[remainingSize + 1];
        strncpy(remainingWord, word + WORD_LENGTH, remainingSize);
        remainingWord[remainingSize] = '\0';
        if (wordIndex + 1 < BLOCK_SIZE)
            setWord(index, wordIndex + 1, remainingWord);
        else if (index + 1 < USER_MEMORY_SIZE)
            setWord(index + 1, 0, remainingWord);
        else
            std::cerr << "Error: Cannot fit word, out of memory space.\n";
        delete[] remainingWord;
    }
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
    
    if (!word) {
        std::cerr << "Error: Null word pointer provided.\n";
        return;
    }
    
    words[index - 256][wordIndex] = *word;
    delete word;
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
UserMemory& Memory::getUserMemoryAddress() { return userMemory; }
