#include "coderunner.hpp"

void openFile(const std::string &programPath, const bool isStepByStep) { // TODO: implent
    // 1. Create Virtual Machine instance
    // 2. Load program from programPath into VM memory (in RM - change RM registers and channel device accordingly)
    // 3. Load program from VM to RM memory step by step (using paging mechanism if needed,
    //      changing channel device and RM registers' values accordingly)
    // 4. Execute program step by step, change VM and RM registers (as well as channel device values) right away accordingly
    // !NOTE!: Commands in VM change registers and memory of VM and RM both,
    //      but commands are executed in RM only
    VirtualMachine vm = VirtualMachine(realMachine.getSFArray(), realMachine.getSPRef(), realMachine.getPCRef(), realMachine.getUserMemoryRef());
    
    system("cls");

    std::ifstream file(programPath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open program file: " + programPath);
    }
    
    std::string line;
    ChannelDevice& cd = realMachine.getChannelDevice();
    bool isData = false, isCode = false, isSuspend = false, isStart = false, isEnd = false;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        if (isStart) {
            isStart = false;
            continue;
        }

        if (line == "..data") {
            isData = true;
            isCode = false;
            isSuspend = false;
            isStart = false;
            isEnd = false;
            cd.setDB(converter.numberAsWord(DATA_SEGMENT_START));
            cd.setST(3);
            cd.setDT(1);
            cd.setCount(0);
            continue;
        } else if (line == "..code") {
            isData = false;
            isCode = true;
            isSuspend = false;
            isStart = false;
            isEnd = false;
            cd.setDB(converter.numberAsWord(CODE_SEGMENT_START));
            cd.setST(3);
            cd.setDT(1);
            cd.setCount(0);
            continue;
        } else if (line == "SUSPND") {
            isData = false;
            isCode = false;
            isSuspend = true;
            isStart = false;
            isEnd = false;
            continue;
        } else if (line == "******") {
            isData = false;
            isCode = false;
            isStart = true;
            isSuspend = false;
            isEnd = false;
            continue;
        } else if (line == "======") {
            isData = false;
            isCode = false;
            isSuspend = false;
            isStart = false;
            isEnd = true;
            continue;
        }

        if (isEnd)
            continue;

        if (isSuspend) {
            executeProgram(vm, isStepByStep);
            continue;
        }

        if (isData) {
            cd.biggerCount();
            dataCommandDetector(isStepByStep, line, vm);
            if (isStepByStep) {
                realMachine.printRegisters();
                system("pause");
                system("cls");
            }
            continue;
        }

        if (isCode) {
            cd.biggerCount();
            codeCommandDetector(isStepByStep, line, vm);
            if (isStepByStep) {
                realMachine.printRegisters();
                system("pause");
                system("cls");
            }
            continue;
        }
        
    }
    
    delete &cd;
    file.close();
}

void runProgram(const std::string &programPath, const bool isStepByStep) { // TODO: implement
    // 1. Create Virtual Machine instance
    // 2. Load program from programPath into VM memory (in RM - change RM registers and channel device accordingly)
    // 3. Load program from VM to RM memory step by step (using paging mechanism if needed,
    //      changing channel device and RM registers' values accordingly)
    // 4. Execute program step by step, change VM and RM registers (as well as channel device values) right away accordingly
    // !NOTE!: Commands in VM change registers and memory of VM and RM both,
    //      but commands are executed in RM only
    VirtualMachine vm = VirtualMachine(realMachine.getSFArray(), realMachine.getSPRef(), realMachine.getPCRef(), realMachine.getUserMemoryRef());
}

void dataCommandDetector(const bool isStepByStep, const std::string& commandLine, VirtualMachine& vm) {
    std::string line = commandLine;
    line.erase(0, line.find_first_not_of(" \t\n\r\f\v"));
    line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
    
    // Find the last symbol (e.g., '$') and remove everything after it
    // size_t lastSymbolPos = line.find_last_of('$');
    // if (lastSymbolPos != std::string::npos) {
    //     line = line.substr(0, lastSymbolPos + 1);
    // }std::cout << line << std::endl;
    // TODO: Process the data command
    if (line == "DW") {
        // TODO: implement
    } else if (line == "DB") {
        // TODO: implement
    } else {
        
    }
}

void codeCommandDetector(const bool isStepByStep, const std::string& commandLine, VirtualMachine& vm) {
    // TODO: implement
}

void executeProgram(VirtualMachine& vm, const bool isStepByStep) {
    // TODO: implement
}