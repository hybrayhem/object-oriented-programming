#include "eight_puzzle.h"
// #include "klotski.h"
// #include "peg_solitaire.h"
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
    // string input;

    // cout << "/* --------------------------- PEG_SOLITAIRE TEST --------------------------- */";
    // BoardGame::PegSolitaire pegame;
    // cout << pegame;

    // // play by string command
    // if (pegame.playUser("e7-u"))
    //     pegame.print("after e7-u", false);
    // cout << "Board score: " << pegame.boardScore() << endl;

    // // play by user input
    // pegame.BoardGame2D::playUser();

    // // play a random move
    // pegame.playAuto();
    // pegame.print("after play auto", false);

    // pegame.playAutoAll();
    // cout << "Board score: " << pegame.boardScore() << endl;

    cout << "\n\n/* ---------------------------- EIGHT_PUZZLE TEST --------------------------- */";
    BoardGame::EightPuzzle epuzzle;
    cout << epuzzle;
    cout << "Board score: " << epuzzle.boardScore() << endl;

    // play by string command
    // if (epuzzle.playUser("a1-u"))
    //     epuzzle.print("after a1-u", false);

    // play by user input
    epuzzle.BoardGame2D::playUser();
    // epuzzle.print("end game", false);

    // play a random move
    // epuzzle.playAuto();
    // epuzzle.print("after play auto", false);

    // play a smart move
    epuzzle.playAutoSmart();
    epuzzle.print("after play auto smart", false);

    cout << "Press enter..." << endl;
    getchar();
    // play smart until end game
    int counter;
    while (!epuzzle.endGame()) {
        for (int i = 0; i < 15; i++)
            cout << endl;
        epuzzle.playAutoSmart();
        epuzzle.print("", false);
        counter++;
    }
    cout << "Solved in " << counter << " moves." << endl;
    cout << "Board score: " << epuzzle.boardScore() << endl;

    // epuzzle.playAutoAll();
    // cout << "Board score: " << epuzzle.boardScore() << endl;

    // cout << "\n\n/* --------------------------------- KLOTSKI -------------------------------- */";
    // Klotski klotski;
    // cout << klotski;

    // // play by string command
    // if (klotski.playUser("6-d"))
    //     klotski.print("after 6-d", false);
    // cout << "Board score: " << klotski.boardScore() << endl;

    // // play by user input
    // klotski.BoardGame2D::playUser();

    // // play a random move
    // klotski.playAuto();
    // klotski.print("after play auto", false);

    // klotski.playAutoAll();
    // cout << "Board score: " << klotski.boardScore() << endl;

    // cout << "\n\n/* ------------------------------- playVector ------------------------------- */";
    // PegSolitaire pegame1, pegame2;
    // EightPuzzle epuzzle1, epuzzle2;
    // Klotski klotski1, klotski2;

    // vector<BoardGame2D *> games = {&pegame1, &pegame2, &epuzzle1, &epuzzle2, &klotski1, &klotski2};
    // BoardGame::BoardGame2D::playVector(games);
    return 0;
}
