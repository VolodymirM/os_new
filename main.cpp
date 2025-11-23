#include "constansandincludes.hpp"
#include "machines.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    RealMachine realMachine;
    realMachine.printRegisters();
    realMachine.printUserMemory("ff");

    VirtualMachine virtualMachine;
    virtualMachine.printRegisters();
    virtualMachine.printUserMemory("ff");
    return 0;
}