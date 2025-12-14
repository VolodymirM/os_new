#include "real.hpp"

void ChannelDevice::makeOperation() {
    // TODO: implement channel device operations
}

RealMachine::RealMachine()
    : channelsDevice(this),
    pagingMechanism(this) {
    initRegisters();
    createSwappingFile();
    this->memory = Memory();
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
}