#include "peg_solitaire.h"
using namespace std;

PegSolitaire::PegSolitaire(char boardID) {
    switch (boardID) {
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

    set_board();
}

PegSolitaire::PegSolitaire(string filename) {
    load_game(filename);
}

PegSolitaire::PegSolitaire() {
    board = board1;
    set_board();
}

void PegSolitaire::set_board() {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            board[i][j].setX(j);
            board[i][j].setY(i);
            totalPeg++;
        }
        cout << endl;
    }
}

void PegSolitaire::print_board(const string msg) {

    cout << "\n   ";
    for (size_t i = 0; i < board[0].size(); i++)
        cout << (char)(97 + i) << " "; // print header row
    if (msg != "") cout << "(" << msg << ")";
    cout << endl;

    for (size_t i = 0; i < board.size(); i++) {
        cout << i + 1 << " "; // print header column
        for (size_t j = 0; j < board[0].size(); j++) {
            switch (board[i][j].getType()) {
            case Cell::cell_t::EMPTY:
                cout << "  ";
                break;
            case Cell::cell_t::PEG:
                cout << " P";
                break;
            case Cell::cell_t::DOT:
                cout << " .";
                break;
            }
            // cout << "(" << board[i][j].getX() << "," << board[i][j].getY() << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

bool PegSolitaire::can_move_to_left(Cell cell) {
    return (cell.getX() - 2 >= 0) && (board[cell.getY()][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY()][cell.getX() - 1].getType() == Cell::cell_t::PEG && board[cell.getY()][cell.getX() - 2].getType() == Cell::cell_t::DOT);
}
bool PegSolitaire::can_move_to_right(Cell cell) {
    return (cell.getX() + 2 < (int)(board[0].size())) && (board[cell.getY()][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY()][cell.getX() + 1].getType() == Cell::cell_t::PEG && board[cell.getY()][cell.getX() + 2].getType() == Cell::cell_t::DOT);
}
bool PegSolitaire::can_move_to_up(Cell cell) {
    return (cell.getY() - 2 >= 0) && (board[cell.getY()][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY() - 1][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY() - 2][cell.getX()].getType() == Cell::cell_t::DOT);
}
bool PegSolitaire::can_move_to_down(Cell cell) {
    return (cell.getY() + 2 < (int)(board.size())) && (board[cell.getY()][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY() + 1][cell.getX()].getType() == Cell::cell_t::PEG && board[cell.getY() + 2][cell.getX()].getType() == Cell::cell_t::DOT);
}

int PegSolitaire::move_left(Cell cell) {
    if (can_move_to_left(cell)) {
        board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY()][cell.getX() - 1].setType(Cell::cell_t::DOT);
        board[cell.getY()][cell.getX() - 2].setType(Cell::cell_t::PEG);
        totalPeg--;
        return 1;
    }
    return 0;
}

int PegSolitaire::move_right(Cell cell) {
    if (can_move_to_right(cell)) {
        board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY()][cell.getX() + 1].setType(Cell::cell_t::DOT);
        board[cell.getY()][cell.getX() + 2].setType(Cell::cell_t::PEG);
        totalPeg--;
        return 1;
    }
    return 0;
}

int PegSolitaire::move_up(Cell cell) {
    if (can_move_to_up(cell)) {
        board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY() - 1][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY() - 2][cell.getX()].setType(Cell::cell_t::PEG);
        totalPeg--;
        return 1;
    }
    return 0;
}

int PegSolitaire::move_down(Cell cell) {
    if (can_move_to_down(cell)) {
        board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY() + 1][cell.getX()].setType(Cell::cell_t::DOT);
        board[cell.getY() + 2][cell.getX()].setType(Cell::cell_t::PEG);
        totalPeg--;
        return 1;
    }
    return 0;
}

void PegSolitaire::load_game(string filename) {
    ifstream inStream;
    string buffer;

    inStream.open(filename, fstream::in);
    if (inStream.fail()) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(0);
    }

    getline(inStream, buffer);
    pegsOut = stoi(buffer);

    board.clear(); // delete all items of old board
    while (!inStream.eof()) {
        vector<Cell> tempBoard;
        getline(inStream, buffer);
        for (auto c : buffer) {
            switch (c) {
            case '-':
                tempBoard.push_back(Cell::cell_t::EMPTY);
                break;
            case 'P':
                tempBoard.push_back(Cell::cell_t::PEG);
                break;
            case '.':
                tempBoard.push_back(Cell::cell_t::DOT);
                break;
            }
        }
        if (!tempBoard.empty()) board.push_back(tempBoard); // avoid pushing empty items, in case of empty file
    }
    inStream.close();

    set_board();
}

void PegSolitaire::save_game(string filename) {
    ofstream outStream;

    outStream.open(filename, fstream::out);
    if (outStream.fail()) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(0);
    }

    outStream << getNumberOfPegsOut() << endl;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            switch (board[i][j].getType()) {
            case Cell::cell_t::EMPTY:
                outStream << "-";
                break;
            case Cell::cell_t::PEG:
                outStream << "P";
                break;
            case Cell::cell_t::DOT:
                outStream << ".";
                break;
            }
        }
        outStream << endl;
    }
    outStream.close();
}

int PegSolitaire::getNumberOfPegs() const {
    int peg = 0;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j].getType() == PegSolitaire::Cell::cell_t::PEG) peg++;
        }
    }
    return peg;
}

int PegSolitaire::getNumberOfEmpty() {
    int empty = 0;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j].getType() == PegSolitaire::Cell::cell_t::EMPTY) empty++;
        }
    }
    return empty;
}

int PegSolitaire::getNumberOfPegsOut() {
    int out = 0;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j].getType() == PegSolitaire::Cell::cell_t::DOT) out++;
        }
    }
    return out - 1; // one of the dots is initial
}

int PegSolitaire::getTotalNumberOfPegs() {
    return totalPeg;
}

bool PegSolitaire::compareGames(PegSolitaire game1, PegSolitaire game2) {
    return (game1.getNumberOfPegs() > game2.getNumberOfPegs());
}

vector<int> PegSolitaire::get_random_valid_move() {
    vector<vector<int>> moves;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            vector<int> move;
            if (can_move_to_left(board[i][j])) { //[i, j, 1]
                move.push_back(i);
                move.push_back(j);
                move.push_back(1);
                moves.push_back(move);
            }
            if (can_move_to_right(board[i][j])) { //[i, j, 2]
                move.push_back(i);
                move.push_back(j);
                move.push_back(2);
                moves.push_back(move);
            }
            if (can_move_to_up(board[i][j])) { //[i, j, 3]
                move.push_back(i);
                move.push_back(j);
                move.push_back(3);
                moves.push_back(move);
            }
            if (can_move_to_down(board[i][j])) { //[i, j, 4]
                move.push_back(i);
                move.push_back(j);
                move.push_back(4);
                moves.push_back(move);
            }
        }
    }

    int index = rand() % (int)(moves.size());
    return moves[index]; // random move from all possible moves
}

void PegSolitaire::play() {
    int y, x, success;
    vector<int> move;

    move = get_random_valid_move();

    y = move[0];
    x = move[1];
    cout << "Moving... " << (char)(x + 65) << y + 1 << "-"; // print last command done

    switch (move[2]) {
    case 1:
        success = move_left(board[y][x]);
        cout << "L";
        break;
    case 2:
        success = move_right(board[y][x]);
        cout << "R";
        break;
    case 3:
        success = move_up(board[y][x]);
        cout << "U";
        break;
    case 4:
        success = move_down(board[y][x]);
        cout << "D";
        break;
    }
    cout << "\n\n";

    if (!success) cerr << "\n> OOPS, something went wrong!\n\n"; // for invalid movements
}

int PegSolitaire::getCommand(int &y, int &x, char &direction) {
    string input;

    getline(cin, input);

    // convert char to int, 'A','B','C' -> 0,1,2
    // x = (decltype(x))(column)-65;
    x = (int)(input[0]) - 65;

    // convert char to int, '1','2','3' -> 1,2,3
    y = (int)(input[1]) - 48;
    y--;

    direction = input[3];

    // command validation
    if (input[2] != '-' || x < 0 || y < 0 || y >= (int)(board.size()) || x >= (int)(board[0].size()) || !(direction == 'L' || direction == 'R' || direction == 'U' || direction == 'D')) {
        cerr << "Invalid input." << endl;
        return 0;
    }
    return 1;
}

void PegSolitaire::play(Cell cell, char direction) {
    int y, x, success = 0;

    y = cell.getY();
    x = cell.getX();

    switch (direction) {
    case 'L':
        success = move_left(board[y][x]);
        break;
    case 'R':
        success = move_right(board[y][x]);
        break;
    case 'U':
        success = move_up(board[y][x]);
        break;
    case 'D':
        success = move_down(board[y][x]);
        break;
    }
    if (success == 0) cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements
}

void PegSolitaire::playGame() {
    int success;
    while (true) {
        print_board();

        if (finish()) break;

        vector<int> move = get_random_valid_move();

        int y = move[0];
        int x = move[1];
        cout << "Moving... " << (char)(x + 65) << y + 1 << "-"; // print last command done

        switch (move[2]) {
        case 1:
            success = move_left(board[y][x]);
            cout << "L";
            break;
        case 2:
            success = move_right(board[y][x]);
            cout << "R";
            break;
        case 3:
            success = move_up(board[y][x]);
            cout << "U";
            break;
        case 4:
            success = move_down(board[y][x]);
            cout << "D";
            break;
        }
        cout << "\n\n";

        if (!success) cerr << "\n> OOPS, something went wrong!\n\n"; // for invalid movements
    }
}

int PegSolitaire::finish() {
    for (decltype(board.size()) i = 0; i < board.size(); i++) {
        for (decltype(board[0].size()) j = 0; j < board[0].size(); j++) {
            if ((can_move_to_left(board[i][j])) ||
                (can_move_to_right(board[i][j])) ||
                (can_move_to_up(board[i][j])) ||
                (can_move_to_down(board[i][j]))) {
                return 0;
            }
        }
    }
    return 1;
}