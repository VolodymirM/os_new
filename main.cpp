#include "constansandincludes.hpp"
#include "real.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    cout << "Word testing" << endl;
    Word* word1 = new Word("hello!");

    cout << "Word1: " << word1->getWord() << endl;
    cout << "Word1 as number: " << word1->getWordAsNumber() << "\n" << endl;

    word1->setNumberAsWord(114784820031265);
    cout << word1->getWord() << endl;
    cout << word1->getWordAsNumber() << endl;

    cout << "\nConverter testing" << endl;
    cout << "Hex: " << Converter::hexToNum("1a") << endl;
    cout << Converter::numToHex(26) << endl;
    return 0;
}