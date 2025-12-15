#include "constansandincludes.hpp"
#include "real.hpp"
#include "virtual.hpp"
#include "utils.hpp"
#include "coderunner.hpp"

using namespace std;

void printMenu();
void printProgramsMenu();

RealMachine realMachine;

int main() {
    // realMachine.printRegisters();
    // realMachine.setWord("ff", 0, new Word("Hello!"));
    // realMachine.printUserMemory("ff");

    // cout << "\n";
    // realMachine.setSupervisorWord("100", new Word("World!"));
    // realMachine.printSupervisorMemory("100");
    // cout << "\n";

    // VirtualMachine vm;
    // vm.printRegisters();
    // vm.setWord("ff", 0, new Word("Hello!"));
    // vm.printUserMemory("ff");
    
    // VM test
    // bool SF[6] = {0,0,0,0,0,0};
    // unsigned SP = 0;
    // unsigned PC = 0;
    // UserMemory userMemory;


    // VirtualMachine vm = VirtualMachine(SF, SP, PC, userMemory);
    // SP = 42;
    // PC = 84;
    // SF[0] = 1;
    // userMemory.setWord(0, 0, new Word("Hello!"));
    // vm.printRegisters();
    // vm.setWord(0, 1, new Word("World!"));
    // vm.printMemoryBlock(0);

    // RM test
    // realMachine.setSP(42);
    // realMachine.setPC(84);
    // realMachine.setSI(1);
    // realMachine.setPI(1);
    // realMachine.setSF(2, 1);
    // realMachine.printRegisters();
    // realMachine.setWord(0, 254, "Hello world! Hello world");
    // realMachine.printMemoryBlock(0);
    // realMachine.printMemoryBlock(1);

    openFile("program1.txt", true);

    return 0;
}

void printMenu() {
    cout << "Select an option:\n";
    cout << "1. Run program\n";
    cout << "2. Run program (step by step)\n";
    cout << "0. Exit\n";
}

void printProgramsMenu() {
    cout << "Select a program to run:\n";
    cout << "1. program1.txt\n";
    cout << "0. Back\n";

}