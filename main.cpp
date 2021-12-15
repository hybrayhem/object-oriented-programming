// #include "board_game2d.h"
#include "eight_puzzle.h"
// #include "klotski.h"
#include "peg_solitaire.h"
#include <iostream>
using namespace std;
using namespace BoardGame;

int main() {
    srand(time(NULL));
    string input;
    int success;

    /* --------------------------- PEG_SOLITAIRE TEST --------------------------- */
    BoardGame::PegSolitaire pegame;
    pegame.print("");

    // play by string command
    pegame.playUser("E7-U");
    pegame.print("after E7-U");

    // play by user input
    do {
        cout << "Enter your command(C2-U, G6-L): ";
        getline(cin, input);
        success = pegame.playUser(input);
    } while (success == 0);
    pegame.print("after " + input);

    // play a random move
    pegame.playAuto();
    pegame.print("after play auto");

    cout << "Board score: " << pegame.boardScore() << endl;

    return 0;
}