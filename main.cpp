#include "eight_puzzle.h"
#include "klotski.h"
#include "peg_solitaire.h"
#include <iostream>
using namespace std;
using namespace BoardGame;

void title() {
    cout << "           _____                                             \n          /\\  __\\_          ___              __            "
         << "         /  \\/ \\___\\       / _ \\__ ________ / /__        \n         \\     /___/      / ___/ // /_ /_ // / -_)          "
         << "      /\\_/     \\    \\    /_/   \\_,_//__/__/_/\\__/       \n     /          \\____\\              _____                  "
         << "     \\       _  /    /             / ___/__ ___ _  ___      \n      \\     /_\\/____/             / (_ / _ `/  ' \\/ -_)   "
         << "      /     \\___\\                 \\___/\\_,_/_/_/_/\\__/  \n      \\_/\\  /   /                                          "
         << "          \\/___/                                        v1.2.0\n\n"
         << endl;
}

int main() {
    title();
    srand(time(NULL));
    string input;
    int success;

    /* --------------------------- PEG_SOLITAIRE TEST --------------------------- */
    BoardGame::PegSolitaire pegame;
    cout << pegame;

    // play by string command
    if (pegame.playUser("e7-u"))
        pegame.print("after e7-u");

    // play by user input
    pegame.BoardGame2D::playUser();

    // play a random move
    pegame.playAuto();
    pegame.print("after play auto");

    cout << "Board score: " << pegame.boardScore() << endl;

    /* ---------------------------- EIGHT_PUZZLE TEST --------------------------- */
    BoardGame::EightPuzzle epuzzle;
    cout << epuzzle;

    // play by string command
    if (epuzzle.playUser("a1-u"))
        epuzzle.print("after a1-u");

    // play by user input
    epuzzle.BoardGame2D::playUser();

    // play a random move
    epuzzle.playAuto();
    epuzzle.print("after play auto");

    cout << "Board score: " << epuzzle.boardScore() << endl;

    return 0;
}