#ifndef EIGHT_PUZZLE
#define EIGHT_PUZZLE

#include "board_game2d.h"
#define N 3 // board size

namespace BoardGame {
    class EightPuzzle : public BoardGame2D {
    public:
        EightPuzzle();

        void initialize();                       // creates random sliding puzzle 2d array
        void print(const std::string msg) const; // print well-formatted puzzle

        int playUser(std::string command); // certain move
        void playAuto();                   // random computer move

        int boardScore(); // number of difference between current puzzle and solved, less is better

    private:
        std::vector<std::vector<int>> puzzle;
        int spaceA, spaceB;

        int parseCommand(std::string input, int &a, int &b, char &direction); // read and parse move commands ex: 11u, 24l, 64d

        int move_left(int a, int b);  // move item at [a,b] to left on board
        int move_right(int a, int b); // move item at [a,b] to right on board
        int move_up(int a, int b);    // move item at [a,b] to up on board
        int move_down(int a, int b);  // move item at [a,b] to down on board
        bool endGame();               // checks win status

        // return move vector in {a, b, direction(1,2,3,4 equals l,r,u,d)}
        std::vector<int> get_random_valid_move();

        /*
        * * * * * * * * * * 
        *  1  *  2  *  3  * 
        * * * * * * * * * * 
        *  4  *  5  *  6  * 
        * * * * * * * * * * 
        *  7  *  8  *  □  * 
        * * * * * * * * * * 
        */
        const std::vector<std::vector<int>> initialPuzzle = {{1, 2, 3},
                                                             {4, 5, 6},
                                                             {7, 8, -1}};
    };
}

#endif