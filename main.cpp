#include "constansandincludes.hpp"
#include "machines.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    RealMachine rm;
    rm.printRegisters();
    return 0;
}

void printMenu() {
    cout << "1. Run program\n";
    cout << "2. Run program (step by step)\n";
    cout << "3. Exit\n";
}