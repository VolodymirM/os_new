#include "constansandincludes.hpp"
#include "real.hpp"
#include "virtual.hpp"
#include "utils.hpp"

using namespace std;

void printMenu();
void printProgramsMenu();

RealMachine realMachine;

int main() {
    realMachine.printRegisters();
    realMachine.setWord("ff", 0, new Word("Hello!"));
    realMachine.printUserMemory("ff");

    cout << "\n";
    realMachine.setSupervisorWord("100", new Word("World!"));
    realMachine.printSupervisorMemory("100");
    cout << "-------------------\n";

    VirtualMachine vm;
    vm.printRegisters();
    vm.setWord("ff", 0, new Word("Hello!"));
    vm.printUserMemory("ff");

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