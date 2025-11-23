#ifndef UTILS_HPP
#define UTILS_HPP

#include "constansandincludes.hpp"

class Converter {
public:
    static std::string numToHex(int64_t number);
    static int64_t hexToNum(const std::string hexStr);
    static char* numberAsWord(int64_t number);
    static int64_t wordAsNumber(const char word[6]);
};

extern Converter converter; // Global instance, can be accesed and used anywhere after including this header

class Word {
private:
    char letters[WORD_LENGTH + 1];

public:
    Word();
    Word(const int64_t number);
    Word(const char* initialLetters);
    void setWord(const char* newLetters);
    char* getWord();
    void setLetter(int index, char letter);
    char getLetter(int index);
    void setNumberAsWord(int64_t number);
    int64_t getWordAsNumber();
};

#endif