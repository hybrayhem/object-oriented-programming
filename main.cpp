#include "eight_puzzle.h"
#include "klotski.h"
#include "peg_solitaire.h"
#include <iostream>
using namespace std;
using namespace BoardGame;

void title(){
    cout << "           _____                                             \n          /\\  __\\_          ___              __            " << endl;
    cout << "         /  \\/ \\___\\       / _ \\__ ________ / /__        \n         \\     /___/      / ___/ // /_ /_ // / -_)          " << endl;
    cout << "      /\\_/     \\    \\    /_/   \\_,_//__/__/_/\\__/       \n     /          \\____\\              _____                  " << endl;
    cout << "     \\       _  /    /             / ___/__ ___ _  ___      \n      \\     /_\\/____/             / (_ / _ `/  ' \\/ -_)   " << endl;
    cout << "      /     \\___\\                 \\___/\\_,_/_/_/_/\\__/  \n      \\_/\\  /   /                                          " << endl;
    cout << "          \\/___/                                        v1.2.0\n\n" << endl;
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

    /* ---------------------------- EIGHT_PUZZLE TEST --------------------------- */
    // BoardGame::EightPuzzle epuzzle;

    return 0;
}