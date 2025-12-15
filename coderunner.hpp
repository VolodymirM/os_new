#ifndef CODERUNNER_HPP
#define CODERUNNER_HPP

#include "constansandincludes.hpp"
#include "utils.hpp"
#include "real.hpp"
#include "virtual.hpp"
#include "commands.hpp"

extern RealMachine realMachine;

void openFile(const std::string &programPath, const bool isStepByStep);
void runProgram(const std::string& programPath, const bool isStepByStep);
void executeProgram(VirtualMachine& vm, const bool isStepByStep);
void dataCommandDetector(const bool isStepByStep, const std::string& commandLine, VirtualMachine& vm);
void codeCommandDetector(const bool isStepByStep, const std::string& commandLine, VirtualMachine& vm);

#endif