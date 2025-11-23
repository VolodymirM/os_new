#include "utils.hpp"

Converter converter;

std::string Converter::numToHex(int64_t number) {
    std::string v{};
    std::stringstream ss;
    ss << std::hex << std::nouppercase << number;
    ss >> v;
    return v;
}

int64_t Converter::hexToNum(const std::string hexStr) {
    int64_t v{};
    std::stringstream ss(hexStr);
    ss >> std::hex >> v;
    return v;
}

char* Converter::numberAsWord(int64_t number) {
    char* arr = new char[WORD_LENGTH]{};
    uint64_t absNumber = static_cast<uint64_t>(number);
    bool isNegative = number < 0;
    if (isNegative)
        absNumber = static_cast<uint64_t>(-number);
    for (int i = 0; i < WORD_LENGTH; ++i) {
        arr[WORD_LENGTH - 1 - i] = (absNumber & 0xFF);
        absNumber >>= 8;
    }
    if (isNegative)
        arr[0] |= 0x80;
    else
        arr[0] &= 0x7F;
    return arr;
}

int64_t Converter::wordAsNumber(const char word[6]) {
    bool isNegative = (word[0] & 0x80) != 0;
    uint64_t value = 0;
    unsigned char firstByte = word[0] & 0x7F;
    value = firstByte;
    for (int i = 1; i < WORD_LENGTH; ++i)
        value = (value << 8) | (static_cast<unsigned char>(word[i]));
    if (isNegative)
        return -static_cast<int64_t>(value);
    else
        return static_cast<int64_t>(value);
}

Word::Word() {
    for (int i = 0; i <= WORD_LENGTH; ++i)
        letters[i] = '\0';  // NULL character here (in our documentation it is '-' - change if needed)
}

Word::Word(const int64_t number) {setNumberAsWord(number);}
Word::Word(const char* initialLetters) {setWord(initialLetters);}
char* Word::getWord() {return letters;}

void Word::setWord(const char* newLetters) {
    for (int i = 0; i < WORD_LENGTH; ++i)
        letters[i] = newLetters[i];
    letters[WORD_LENGTH] = '\0'; // Null-terminate the string
}

char Word::getLetter(int index) {
    if (index >= 0 && index < WORD_LENGTH)
        return letters[index];
    return '\0'; // Return null character if index is out of bounds
}

void Word::setLetter(int index, char letter) {
    if (index >= 0 && index < WORD_LENGTH)
        letters[index] = letter;
}

void Word::setNumberAsWord(int64_t number) {
    char* numAsWord = Converter::numberAsWord(number);
    setWord(numAsWord);
    letters[WORD_LENGTH] = '\0';
    delete[] numAsWord;
}

int64_t Word::getWordAsNumber() {return Converter::wordAsNumber(letters);}

Block::Block() {
    for (size_t index = 0; index < BLOCK_SIZE; ++index) {
        cells[index] = new Word();
    }
}

Word& Block::getWord(size_t index) {
    return *cells[index];
}