#include "real.hpp"

void ChannelDevice::printChannelRegisters() {
    std::cout << "Channel Device Registers:\n";
    std::cout << "SB: " << SB.getWordAsHex();
    std::cout << " DB: " << DB.getWordAsHex();
    std::cout << " ST: " << ST;
    std::cout << " DT: " << DT;
    std::cout << " Offset: " << offset;
    std::cout << " Count: " << count << "\n";
}

RealMachine::RealMachine()
    : channelsDevice(this),
    pagingMechanism(this) {
    initRegisters();
    createSwappingFile();
    this->memory = Memory();
}

void RealMachine::makeOperation() {
    // TODO: implement
}

void RealMachine::initRegisters() {
    SP = 0;
    PC = 0;

    for (int i = 0; i < 6; ++i)
        SF[i] = 0;

    PTR = Word();
    MODE = 0;
    PI = 0;
    SI = 0;
    TI = 0;
}

void RealMachine::createSwappingFile() {
    std::ofstream swapFile;
    swapFile.open(SWAP_FILE);
    if (!swapFile.is_open()) {
        std::cerr << "Error creating swapping file.\n";
        return;
    }

    for (int i = 0; i < SWAP_BLOCKS; ++i) {
        swapFile << converter.numToHex(i) << " ";
        for (int j = 0; j < BLOCK_SIZE; ++j)
            swapFile << "------ ";
        if (i != SWAP_BLOCKS - 1)
            swapFile << "\n";
    }

    swapFile.close();
}

void RealMachine::printRegisters() {
    std::cout << "CPU Registers:\n";
    std::cout << "SP: " << SP;
    std::cout << " PC: " << PC;
    std::cout << " SF: ";
    for (int i = 0; i < 6; ++i)
        std::cout << SF[i];
    std::cout << " PTR: " << PTR.getWordAsHex();
    std::cout << " MODE: " << MODE;
    std::cout << " PI: " << PI;
    std::cout << " SI: " << SI;
    std::cout << " TI: " << TI << "\n";
    channelsDevice.printChannelRegisters();
}

void RealMachine::setWord(const size_t blockIndex, const size_t wordIndex, const char* word) {
    if (!word) {
        std::cerr << "Error: Null word provided.\n";
        return;
    }

    if (blockIndex >= USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE || wordIndex >= BLOCK_SIZE) {
        std::cerr << "Error: Memory index out of bounds.\n";
        return;
    }

    unsigned wordSize = strlen(word);
    if (wordSize <= WORD_LENGTH)
        memory.setWord(blockIndex, wordIndex, new Word(word));
    else {
        char extractedWord[WORD_LENGTH + 1] = {0};
        strncpy(extractedWord, word, WORD_LENGTH);
        memory.setWord(blockIndex, wordIndex, new Word(extractedWord));
        size_t remainingSize = wordSize - WORD_LENGTH;
        char* remainingWord = new char[remainingSize + 1];
        strncpy(remainingWord, word + WORD_LENGTH, remainingSize);
        remainingWord[remainingSize] = '\0';
        if (wordIndex + 1 < BLOCK_SIZE)
            setWord(blockIndex, wordIndex + 1, remainingWord);
        else
            setWord(blockIndex + 1, 0, remainingWord);
        delete[] remainingWord;
    }
}

void RealMachine::setWord(const size_t absoluteIndex, const size_t wordIndex, int64_t number) {
    if (absoluteIndex >= USER_MEMORY_SIZE + SUPERVISOR_MEMORY_SIZE || wordIndex >= BLOCK_SIZE) {
        std::cerr << "Error: Memory index out of bounds.\n";
        return;
    }

    memory.setWord(absoluteIndex, wordIndex, new Word(number));
}