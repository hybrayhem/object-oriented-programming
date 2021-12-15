#include "eight_puzzle.h"
#include "klotski.h"
#include "peg_solitaire.h"
#include <iostream>
using namespace std;
using namespace BoardGame;

void title() {
    cout << "           _____                                             \n          /\\  __\\_          ___              __            " << endl
         << "         /  \\/ \\___\\       / _ \\__ ________ / /__        \n         \\     /___/      / ___/ // /_ /_ // / -_)          " << endl
         << "      /\\_/     \\    \\    /_/   \\_,_//__/__/_/\\__/       \n     /          \\____\\              _____                  " << endl
         << "     \\       _  /    /             / ___/__ ___ _  ___      \n      \\     /_\\/____/             / (_ / _ `/  ' \\/ -_)   " << endl
         << "      /     \\___\\                 \\___/\\_,_/_/_/_/\\__/  \n      \\_/\\  /   /                                          " << endl
         << "          \\/___/                                        v1.2.0\n\n"
         << endl;
}

int main() {
    title();
    srand(time(NULL));
    string input;

    /* --------------------------- PEG_SOLITAIRE TEST --------------------------- */
    BoardGame::PegSolitaire pegame;
    cout << pegame;

    // play by string command
    if (pegame.playUser("e7-u"))
        pegame.print("after e7-u", false);

    // play by user input
    //TODO: pegame.BoardGame2D::playUser();

    // play a random move
    pegame.playAuto();
    pegame.print("after play auto", false);

    pegame.playAutoAll();
    cout << "Board score: " << pegame.boardScore() << endl;

    /* ---------------------------- EIGHT_PUZZLE TEST --------------------------- */
    BoardGame::EightPuzzle epuzzle;
    cout << epuzzle;

    // play by string command
    if (epuzzle.playUser("a1-u"))
        epuzzle.print("after a1-u", false);

    // play by user input
    //TODO: epuzzle.BoardGame2D::playUser();

    // play a random move
    epuzzle.playAuto();
    epuzzle.print("after play auto", false);

    epuzzle.playAutoAll();
    cout << "Board score: " << epuzzle.boardScore() << endl;

    /* --------------------------------- KLOTSKI -------------------------------- */


    /* ------------------------------- playVector ------------------------------- */
    PegSolitaire pegame1, pegame2;
    EightPuzzle epuzzle1, epuzzle2;
    // Klotski klotski1, klotski2;

    vector<BoardGame2D*> games = {&pegame1, &pegame2, &epuzzle1, &epuzzle2};
    // BoardGame2D::playVector(games);
    return 0;
}