#include "constansandincludes.hpp"
#include "real.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    Real realMachine;
    realMachine.printRegisters();
    realMachine.printUserMemory("ff");

    VirtualMachine virtualMachine;
    virtualMachine.printRegisters();
    virtualMachine.printUserMemory("ff");
    return 0;
}