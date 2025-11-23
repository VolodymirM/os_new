#include "constansandincludes.hpp"
#include "real.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    Memory memory;
    memory.setWord(10, 0, new Word("Hello!"));
    cout << "Word at address 10, index 0 as number: " << memory.getWord(10, 0).getWordAsNumber() << endl;
    cout << "Word at address 10, index 0 as hex: " << memory.getWord(10, 0).getWord() << endl;
    cout << "Word at address 10, index 0 as hex string: " << memory.getWord(10, 0).getWordAsHex() << endl;

    memory.setSupervisorWord(256, new Word(79600447942433));
    cout << "Supervisor word at address 256 as number: " << memory.getSupervisorWord(256).getWordAsNumber() << endl;
    cout << "Supervisor word at address 256 as hex: " << memory.getSupervisorWord(256).getWord() << endl;
    cout << "Supervisor word at address 256 as hex string: " << memory.getSupervisorWord(256).getWordAsHex() << endl;
    return 0;
}