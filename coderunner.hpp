#ifndef CODERUNNER_HPP
#define CODERUNNER_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "real.hpp"
#include "virtual.hpp"

extern RealMachine realMachine;

void runProgram(const std::string& programPath);
void runProgramStepByStep(const std::string& programPath);

#endif