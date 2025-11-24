#include "coderunner.hpp"

void runProgram(const std::string &programPath) { // TODO: implent
    // 1. Create Virtual Machine instance
    // 2. Load program from programPath into VM memory (in RM - change RM registers and channel device accordingly)
    // 3. Load program from VM to RM memory step by step (using paging mechanism if needed,
    //      changing channel device and RM registers' values accordingly)
    // 4. Execute program step by step, change VM and RM registers (as well as channel device values) right away accordingly
    // !NOTE!: Commands in VM change registers and memory of VM and RM both,
    //      but commands are executed in RM only

}

void runProgramStepByStep(const std::string &programPath) { // TODO: implement
    // the same as runProgram but step by step with user input to continue each step
}