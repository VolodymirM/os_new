#include "commands.hpp"

void DW(const bool isStepByStep) {
    // TODO: implement
}

void DW(const bool isStepByStep, const std::string& value) {
    if (isStepByStep)
        std::cout << "DW command executed with value: " << value << std::endl;
}

void DB(const bool isStepByStep) {
    // TODO: implement
}

void DB(const bool isStepByStep, const std::string& value) {
    std::string val;
    if (value.length() > 2 && const_cast<Word&>(realMachine.getChannelDevice().getDB()).getWordAsNumber() <= DATA_SEGMENT_END) {
        val = value.substr(1, value.length() - 3);
        realMachine.setWord(const_cast<Word&>(realMachine.getChannelDevice().getDB()).getWordAsNumber(), realMachine.getChannelDevice().getCount() - 1, val.c_str());
        if (isStepByStep)
            realMachine.printMemoryBlock(const_cast<Word&>(realMachine.getChannelDevice().getDB()).getWordAsNumber());
    }
    else
        std::cout << "DB command error: value too short." << std::endl;

}