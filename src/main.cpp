#include "main.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // elements of move
    int y, x;
    char direction;

    // input buffers
    int success;
    char selection = 0;
    string filename;
    vector<int> move;

    srand(time(NULL));

    vector<vector<BoardItem>> board;
    cout << "▧ ▧ ▧ Peg Solitaire ▧ ▧ ▧\n\n";

    // ask and fill from predefined boards
    set_board(board);
    print_board(board);

    do {
        // MENU
        cout << "\n1. Human Player Game\n"
             << "2. Computer Game\n"
             << "3. Load Game File\n"
             << "0. Exit\n";
        selection = get_selection("Please select an operation: ", '0', '3');

        // LOAD GAME
        if (selection == '3') {
            cout << "Enter file name: ";
            getline(cin, filename);
            cout << endl;
            load_game(selection, board, filename);
        }

        // HUMAN PLAYER
        if (selection == '1') {
            cout << "\n> INFO: movement format is [vertical_index][horizontal_index]-[u, d, l or r]\n> ex: C2-L, A5-U\n> type 0 for exit the menu \n> type SAVE for save current game\n\n\n";

            while (true) {
                print_board(board);

                if (you_won(board)) finish(board, 1);

                do {
                    cout << "Enter your command(C2-L, A5-U, SAVE): ";
                    success = get_command(y, x, direction, board);
                } while (success == 0);
                if (success == -1) break;

                switch (direction) {
                case 'L':
                    success = move_left(board, y, x);
                    break;
                case 'R':
                    success = move_right(board, y, x);
                    break;
                case 'U':
                    success = move_up(board, y, x);
                    break;
                case 'D':
                    success = move_down(board, y, x);
                    break;
                }
                if (!success) cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements
            }
        }
        // COMPUTER GAME
        else if (selection == '2') {
            while (true) {
                print_board(board);

                if (you_won(board)) finish(board, 2);

                move = get_random_valid_move(board);

                y = move[0];
                x = move[1];
                cout << "Moving... " << (char)(x + 65) << y + 1 << "-"; // print last command done

                switch (move[2]) {
                case 1:
                    success = move_left(board, y, x);
                    cout << "L";
                    break;
                case 2:
                    success = move_right(board, y, x);
                    cout << "R";
                    break;
                case 3:
                    success = move_up(board, y, x);
                    cout << "U";
                    break;
                case 4:
                    success = move_down(board, y, x);
                    cout << "D";
                    break;
                }
                cout << "\n\n";

                if (!success) cerr << "\n> OOPS, something went wrong!\n\n"; // for invalid movements
            }
        }
    } while (selection != '0');

    return 0;
}

void load_game(char &gameType, vector<vector<BoardItem>> &board, string filename) {
    ifstream inStream;
    string buffer;

    inStream.open(filename, fstream::in);
    if (inStream.fail()) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(0);
    }

    getline(inStream, buffer);
    gameType = buffer[0];

    board.clear(); // delete all items of old board
    while (!inStream.eof()) {
        vector<BoardItem> tempBoard;
        getline(inStream, buffer);
        for (auto c: buffer){
            switch (c) {
            case '-':
                tempBoard.push_back(BoardItem::EMPTY);
                break;
            case 'P':
                tempBoard.push_back(BoardItem::PEG);
                break;
            case '.':
                tempBoard.push_back(BoardItem::DOT);
                break;
            }
        }
        if (!tempBoard.empty()) board.push_back(tempBoard); // avoid pushing empty items, in case of empty file
    }
    inStream.close();
}

void save_game(int gameType, const vector<vector<BoardItem>> &board, string filename) {
    ofstream outStream;

    outStream.open(filename, fstream::out);
    if (outStream.fail()) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(0);
    }

    outStream << gameType << endl;
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            switch (board[i][j]) {
            case BoardItem::EMPTY:
                outStream << "-";
                break;
            case BoardItem::PEG:
                outStream << "P";
                break;
            case BoardItem::DOT:
                outStream << ".";
                break;
            }
        }
        outStream << endl;
    }
    outStream.close();
}

void finish(const vector<vector<BoardItem>> &board, int gameType) {
    char save;
    string filename;

    cout << "\nGame over.\n"; // end message
    cout << get_score(board) << " points.\n\n"
         << endl;

    save = get_selection("Do you want to save the game? (y/n)\n", 'a', 'z');
    if (save == 'y') {
        cout << "Enter file name: ";
        getline(cin, filename);
        cout << endl;
        save_game(gameType, board, filename);
    }
    exit(1);
}

int get_score(const vector<vector<BoardItem>> &board) {
    int score = 0;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if (board[i][j] == BoardItem::PEG) score++;
        }
    }
    return score;
}

vector<int> get_random_valid_move(const vector<vector<BoardItem>> &board) {
    vector<vector<int>> moves;

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            vector<int> move;
            if (can_move_to_left(board, i, j)) { //[i, j, 1]
                move.push_back(i);
                move.push_back(j);
                move.push_back(1);
                moves.push_back(move);
            }
            if (can_move_to_right(board, i, j)) { //[i, j, 2]
                move.push_back(i);
                move.push_back(j);
                move.push_back(2);
                moves.push_back(move);
            }
            if (can_move_to_up(board, i, j)) { //[i, j, 3]
                move.push_back(i);
                move.push_back(j);
                move.push_back(3);
                moves.push_back(move);
            }
            if (can_move_to_down(board, i, j)) { //[i, j, 4]
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

char get_selection(const string msg, char lower, char upper) {
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

int get_command(int &y, int &x, char &direction, const vector<vector<BoardItem>> &board) {
    string input, filename;

    getline(cin, input);

    // save board to continue game later
    if (input == "SAVE" || input == "save") {
        cout << "Enter file name: ";
        getline(cin, filename);
        cout << endl;
        save_game(1, board, filename);
        return 1;
    }

    if (input[0] == '0') {
        return -1;
    }

    // convert char to int, 'A','B','C' -> 0,1,2
    // x = (decltype(x))(column)-65;
    x = (int)(input[0])-65;

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

void set_board(vector<vector<BoardItem>> &board) {
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

int you_won(const vector<vector<BoardItem>> &board) {

    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[0].size(); j++) {
            if ((can_move_to_left(board, i, j)) ||
                (can_move_to_right(board, i, j)) ||
                (can_move_to_up(board, i, j)) ||
                (can_move_to_down(board, i, j))) {
                return 0;
            }
        }
    }
    return 1;
}

void print_board(const vector<vector<BoardItem>> &board) {
    
    cout << "\n   ";
    for (size_t i = 0; i < board[0].size(); i++)
        cout << (char)(97 + i) << " "; // print header row
    cout << endl;

    for (size_t i = 0; i < board.size(); i++) {
        cout << i + 1 << " "; // print header column
        for (size_t j = 0; j < board[0].size(); j++) {
            switch (board[i][j]) {
            case BoardItem::EMPTY:
                cout << "  ";
                break;
            case BoardItem::PEG:
                cout << " P";
                break;
            case BoardItem::DOT:
                cout << " .";
                break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool can_move_to_left(const vector<vector<BoardItem>> &board, int y, int x) {
    return (x - 2 >= 0) && (board[y][x] == BoardItem::PEG && board[y][x - 1] == BoardItem::PEG && board[y][x - 2] == BoardItem::DOT);
}
bool can_move_to_right(const vector<vector<BoardItem>> &board, int y, int x) {
    return (x + 2 < (int)(board[0].size())) && (board[y][x] == BoardItem::PEG && board[y][x + 1] == BoardItem::PEG && board[y][x + 2] == BoardItem::DOT);
}
bool can_move_to_up(const vector<vector<BoardItem>> &board, int y, int x) {
    return (y - 2 >= 0) && (board[y][x] == BoardItem::PEG && board[y - 1][x] == BoardItem::PEG && board[y - 2][x] == BoardItem::DOT);
}
bool can_move_to_down(const vector<vector<BoardItem>> &board, int y, int x) {
    return (y + 2 < (int)(board.size())) && (board[y][x] == BoardItem::PEG && board[y + 1][x] == BoardItem::PEG && board[y + 2][x] == BoardItem::DOT);
}

int move_left(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_left(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y][x - 1] = BoardItem::DOT;
        board[y][x - 2] = BoardItem::PEG;
        return 1;
    }
    return 0;
}

int move_right(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_right(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y][x + 1] = BoardItem::DOT;
        board[y][x + 2] = BoardItem::PEG;
        return 1;
    }
    return 0;
}

int move_up(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_up(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y - 1][x] = BoardItem::DOT;
        board[y - 2][x] = BoardItem::PEG;
        return 1;
    }
    return 0;
}

int move_down(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_down(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y + 1][x] = BoardItem::DOT;
        board[y + 2][x] = BoardItem::PEG;
        return 1;
    }
    return 0;
}
