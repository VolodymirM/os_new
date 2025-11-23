#include "constansandincludes.hpp"
#include "real.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    Memory memory;
    memory.setWord(0, 0, new Word("Hello!"));
    cout << "Word at address 0, index 0 as number: " << memory.getWord(0, 0).getWordAsNumber() << endl;
    cout << "Word at address 0, index 0 as hex: " << memory.getWord(0, 0).getWord() << endl;

    memory.setSupervisorWord(256, new Word(79600447942433));
    cout << "Supervisor word at address 256 as number: " << memory.getSupervisorWord(256).getWordAsNumber() << endl;
    cout << "Supervisor word at address 256 as hex: " << memory.getSupervisorWord(256).getWord() << endl;
    return 0;
}