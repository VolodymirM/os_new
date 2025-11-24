#include "constansandincludes.hpp"
#include "real.hpp"
#include "virtual.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    RealMachine rm;
    rm.printRegisters();
    rm.setWord("ff", 0, new Word("Hello!"));
    rm.printUserMemory("ff");

    cout << "\n";
    rm.setSupervisorWord("100", new Word("World!"));
    rm.printSupervisorMemory("100");

    cout << "-------------------\n";

    VirtualMachine vm;
    vm.printRegisters();
    vm.setWord("ff", 0, new Word("Hello!"));
    vm.printUserMemory("ff");
    return 0;
}

void printMenu() {
    cout << "1. Run program\n";
    cout << "2. Run program (step by step)\n";
    cout << "3. Exit\n";
}