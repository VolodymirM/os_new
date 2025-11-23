#include "real.hpp"

Real::Real() {
    initRegisters();
    memory = new Memory();
}

void Real::initRegisters() {
    for (int i = 0; i < 4; ++i) {
        SP[i] = 0;
        PC[i] = 0;
        SF[i] = 0;
    }

    for (int i = 4; i < 6; ++i)
        SF[i] = 0;

    PTR = Word();
    MODE = 0;
    PI = 0;
    SI = 0;
    TI = 0;
}