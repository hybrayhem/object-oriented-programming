#include <iostream>
#include <vector>
using namespace std;

class PegSolitaire {

public:
    // PegSolitaire(){};
    // PegSolitaire(){};
    PegSolitaire(int boardNum){};

    class Cell {
        int x, y; // TODO: row getter should return char
    public:
        enum type_t {
            PEG,
            DOT,
            EMPTY
        };
        type_t type;

        Cell(type_t cellType) : type(cellType){};
    };


    // static int totalPegNumber();
    // bool compare_games(PegSolitaire game1, PegSolitaire game2);
    // void read_game();
    // void write_game();
    void set_board(vector<vector<Cell>> &board);
    void print_board(const vector<vector<Cell>> &board);

    
private:
    vector<vector<Cell>> board;

    void play();                            // computer move
    void play(int y, int x, int direction); // certain move
    void playGame();                        // ask for input then perform the move
    char get_selection(const string msg, char lower, char upper);

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
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::DOT), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
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
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::DOT), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
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
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::DOT), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
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
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::DOT), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
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
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::DOT), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
    };

    /*
    . - - - -
    P P - - -
    P P P - -
    P P P P -
    P P P P P
    */
    const vector<vector<Cell>> board6 = {
        {Cell(Cell::type_t::DOT), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::EMPTY)},
        {Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG), Cell(Cell::type_t::PEG)},
    };
};

char PegSolitaire::get_selection(const string msg, char lower, char upper) {
    int flag = 0;
    char selection = 0;

    while (!flag) {
        if (msg[0] != '\0') cout << msg;
        cin >> selection;
        while (getchar() != '\n')
            ; // remove unnecessary characters
        if (selection < lower || selection > upper) {
            cout << "TRY AGAIN" << endl;
            continue;
        }
        flag = 1;
    }
    return selection;
}

void PegSolitaire::set_board(vector<vector<Cell>> &board){
    
    char selection = get_selection("> Select the board 1-6: ", '1', '6');

    switch (selection) {
    case '1':
        board = board1;
        break;
    case '2':
        board = board2;
        break;
    case '3':
        board = board3;
        break;
    case '4':
        board = board4;
        break;
    case '5':
        board = board5;
        break;
    case '6':
        board = board6;
        break;
    }
}