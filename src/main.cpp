#include "main.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int y, x;
    char direction;
    int success;
    char selection;
    int move;

    srand(time(NULL));

    vector<vector<BoardItem>> board;
    cout << "▧ ▧ ▧ Peg Solitaire ▧ ▧ ▧\n\n";
    set_board(board);

    cout << "1. Human Player Game\n"
         << "2. Computer Game\n";
    selection = get_selection("Please select an operation: ", '1', '2');

    if (selection == '1') {
        cout << "\n> INFO: movement format is [vertical_index][horizontal_index]-[u, d, l or r]\n> ex: C2-L, A5-U\n> type 0 for exit the game\n\n\n";

        while (true) {
            print_board(board);

            if (you_won(board)) break;

            do {
                cout << "Enter your command(C2-L, A5-U): ";
            } while (get_command(y, x, direction, get_score(board)) != 1);
            
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
            if (!success) printf("\n> OOPS! I can't move to that direction!\n\n"); /* for invalid movements */
        }
    } else if (selection == '2') {
        while (true) {
            print_board(board);

            if (you_won(board)) break;

            move = get_random_valid_move(board);
            // cout << "move: " << move << " " << move / 100 << " " << (move / 10) % 10 << " " << move % 10 << endl;

            switch (move % 10) {
            case 1:
                success = move_left(board, move / 100, (move / 10) % 10); // divide move 234 input to 2, 3, 4
                break;
            case 2:
                success = move_right(board, move / 100, (move / 10) % 10);
                break;
            case 3:
                success = move_up(board, move / 100, (move / 10) % 10);
                break;
            case 4:
                success = move_down(board, move / 100, (move / 10) % 10);
                break;
            }
            if (!success) printf("\n> OOPS! I can't move to that direction!\n\n"); /* for invalid movements */
        }
    }
    cout << "\nGame over.\n"; /* say bye to user */

    cout << get_score(board) << " points.\n\n"
         << endl;
    return 0;
}

int get_score(const vector<vector<BoardItem>> &board) {
    int score = 0;

    int h = board.size();
    int w = board[0].size();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == BoardItem::PEG) score++;
        }
    }
    return score;
}

int get_random_valid_move(const vector<vector<BoardItem>> &board) {
    int h = board.size();
    int w = board[0].size();

    vector<int> moves;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (can_move_to_left(board, i, j)) { //ij1
                moves.push_back(i * 100 + j * 10 + 1);
            }
            if (can_move_to_right(board, i, j)) { //ij2
                moves.push_back(i * 100 + j * 10 + 2);
            }
            if (can_move_to_up(board, i, j)) { //ij3
                moves.push_back(i * 100 + j * 10 + 3);
            }
            if (can_move_to_down(board, i, j)) { //ij4
                moves.push_back(i * 100 + j * 10 + 4);
            }
        }
    }

    // debug prints
    // for (int i : moves)
    //     cout << i << ' ';

    int index = rand() % (int)(moves.size());
    // cout << endl
    //      << "random move = " << moves[index] << endl;
    return moves[index];
}

char get_selection(const string msg, char lower, char upper) {
    int flag = 0;
    char selection = 0;

    while (!flag) {
        if (msg[0] != '\0') cout << msg;
        cin >> selection;
        if (selection < lower || selection > upper) {
            cout << "TRY AGAIN" << endl;
            continue;
        }
        flag = 1;
    }
    return selection;
}

int get_command(int &y, int &x, char &direction, int score) {
    char column;
    cin >> column;
    if (column == '0') {
        cout << "\nGame over.\n"; /* say bye to user */
        cout << score << " points.\n\n";
        exit(0); // 0 is exit
    }

    x = (int)(column)-65;
    cin >> y;
    y--;
    cin >> direction;
    if (direction != '-') cout << "Invalid input." << endl;
    cin >> direction;

    if (x >= 9 || y >= 9 || !(direction == 'L' || direction == 'R' || direction == 'U' || direction == 'D')) return 0; //input validation
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
    int h = board.size();
    int w = board[0].size();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
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

void print_board(const vector<vector<BoardItem>> board) {
    int h = board.size();
    int w = board[0].size();

    // cout << "height: " << h << "  width: " << w << endl;

    cout << "   ";
    for (int i = 0; i < w; i++)
        cout << (char)(97 + i) << " "; // print header row
    cout << endl;

    for (int i = 0; i < h; i++) {
        cout << i + 1 << " "; // print header column
        // if(board[0][1] == BoardItem::EMPTY) cout << string(h - i - 1, ' '); // Exception for Board 6
        for (int j = 0; j < w; j++) {
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
    cout << "y: " << y << " x: " << x << "\n"
         << (int)(board[y][x]);
    return 0;
}

int move_right(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_right(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y][x + 1] = BoardItem::DOT;
        board[y][x + 2] = BoardItem::PEG;
        return 1;
    }
    cout << "y: " << y << " x: " << x << "\n"
         << (int)(board[y][x]);
    return 0;
}

int move_up(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_up(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y - 1][x] = BoardItem::DOT;
        board[y - 2][x] = BoardItem::PEG;
        return 1;
    }
    cout << "y: " << y << " x: " << x << "\n"
         << (int)(board[y][x]);
    return 0;
}

int move_down(vector<vector<BoardItem>> &board, int y, int x) {
    if (can_move_to_down(board, y, x)) {
        board[y][x] = BoardItem::DOT;
        board[y + 1][x] = BoardItem::DOT;
        board[y + 2][x] = BoardItem::PEG;
        return 1;
    }
    cout << "y: " << y << " x: " << x << "\n"
         << (int)(board[y][x]);
    return 0;
}
