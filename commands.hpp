#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "real.hpp"
#include "virtual.hpp"

extern RealMachine realMachine;

// Data segment commands
void DW(const bool isStepByStep);
void DW(const bool isStepByStep, const std::string& value);
void DB(const bool isStepByStep);
void DB(const bool isStepByStep, const std::string& value);

// Code segment commands

#endif