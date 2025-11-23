#ifndef REAL_HPP
#define REAL_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "realcomponents.hpp"

class Real {
private:
    char SP[4];
    char PC[4];
    bool SF[6];
    Word PTR;
    bool MODE;
    bool PI;
    unsigned SI;
    bool TI;
    Memory* memory;

    void initRegisters();

public:
    Real();

};

#endif