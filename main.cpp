#include "constansandincludes.hpp"
#include "real.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    Real realMachine;
    realMachine.printUserMemory(21);
    realMachine.printSupervisorMemory("1ff");
    return 0;
}