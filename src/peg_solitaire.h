#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PegSolitaire {

public:
    PegSolitaire(char boardID);
    PegSolitaire(string filename);
    PegSolitaire(); // default constructor
    static int totalPeg;

    class Cell {
        int x, y;

    public:
        enum cell_t {
            PEG,
            DOT,
            EMPTY
        };
        cell_t type;

        Cell(cell_t cellType) : type(cellType){};
        Cell(int x, int y) : x(x), y(y){};

        inline int getX() {
            return x;
        }

        inline int getY() {
            return y;
        }

        void setX(int _x) {
            x = _x;
        }

        void setY(int _y) {
            y = _y;
        }

        cell_t getType() const {
            return type;
        }

        void setType(cell_t cellType) {
            type = cellType;
        }
    };

    static int getTotalNumberOfPegs(); // number of pegs from all objects

    static bool compareGames(PegSolitaire game1, PegSolitaire game2); // return true if the first game has more pegs, else return false
    void set_board(); // set x,y values of cells
    void print_board(const string msg = ""); 
    void load_game(string filename = "game.txt"); // load existing game from file
    void save_game(string filename = "game.txt"); // save game to a file
    int getNumberOfPegs() const; // count pegs on board
    int getNumberOfEmpty(); // count empty cells on board
    int getNumberOfPegsOut(); // count pegs taken out in game

    void play();                          // random computer move
    void play(Cell cell, char direction); // certain move
    void playGame();                      // ask for input then finish the game
    int getCommand(int &y, int &x, char &direction); // read and parse move commands ex: B4-U

private:
    vector<vector<Cell>> board;
    int pegsOut = 0;

    bool can_move_to_left(Cell cell); // check the peg at board[y][x] can move to left 
    bool can_move_to_right(Cell cell); // check the peg at board[y][x] can move to right
    bool can_move_to_up(Cell cell); // check the peg at board[y][x] can move to up 
    bool can_move_to_down(Cell cell); // check the peg at board[y][x] can move to down
    int move_left(Cell cell); // take the target peg and move two square left over another peg
    int move_right(Cell cell); // take the target peg and move two square right over another peg
    int move_up(Cell cell); // take the target peg and move two square up over another peg
    int move_down(Cell cell); // take the target peg and move two square down over another peg
    int finish(); // return 1 on no valid move exists

    // return move vector in {y, x, direction(1,2,3,4 equals l,r,u,d)}
    vector<int> get_random_valid_move();

    // Pre-defined boards
    /*
    - - P P P - -
    - P P P P P -
    P P P . P P P
    P P P P P P P
    P P P P P P P
    - P P P P P -
    - - P P P - -
    */
    const vector<vector<Cell>> board1 = {
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
    };

    /*
    - - - P P P - - -
    - - - P P P - - -
    - - - P P P - - -
    P P P P P P P P P
    P P P P . P P P P
    P P P P P P P P P
    - - - P P P - - -
    - - - P P P - - -
    - - - P P P - - -
    */
    const vector<vector<Cell>> board2 = {
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
    };

    /*
    - - P P P - - -
    - - P P P - - -
    - - P P P - - -
    P P P P P P P P
    P P P . P P P P
    P P P P P P P P
    - - P P P - - -
    - - P P P - - -
    */
    const vector<vector<Cell>> board3 = {
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
    };

    /*
    - - P P P - -
    - - P P P - -
    P P P P P P P
    P P P . P P P
    P P P P P P P
    - - P P P - -
    - - P P P - -
    */
    const vector<vector<Cell>> board4 = {
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
    };

    /*
    - - - - P - - - -
    - - - P P P - - -
    - - P P P P P - -
    - P P P P P P P -
    P P P P . P P P P
    - P P P P P P P -
    - - P P P P P - -
    - - - P P P - - -
    - - - - P - - - -
    */
    const vector<vector<Cell>> board5 = {
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
    };

    /*
    . - - - -
    P P - - -
    P P P - -
    P P P P -
    P P P P P
    */
    const vector<vector<Cell>> board6 = {
        {Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY)},
        {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
    };
};
