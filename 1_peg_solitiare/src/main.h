#include "boards.h"
#include <iostream>
#include <vector>

// print well formatted board
void print_board(const vector<vector<BoardItem>> board);

// check the peg at board[y][x] can move to left 
bool can_move_to_left(const vector<vector<BoardItem>> &board, int y, int x);

// check the peg at board[y][x] can move to right
bool can_move_to_right(const vector<vector<BoardItem>> &board, int y, int x);

// check the peg at board[y][x] can move to up 
bool can_move_to_up(const vector<vector<BoardItem>> &board, int y, int x);

// check the peg at board[y][x] can move to down
bool can_move_to_down(const vector<vector<BoardItem>> &board, int y, int x);

// take the target peg and move two square left over another peg
int move_left(vector<vector<BoardItem>> &board, int y, int x);

// take the target peg and move two square right over another peg
int move_right(vector<vector<BoardItem>> &board, int y, int x);

// take the target peg and move two square up over another peg
int move_up(vector<vector<BoardItem>> &board, int y, int x);

// take the target peg and move two square down over another peg
int move_down(vector<vector<BoardItem>> &board, int y, int x);

/* secure cin function that gets the selection for menu with a bullet-proof error handling */
char get_selection(const string msg, char lower, char upper);

/* read and parse move commands ex: B4-U */
int get_command(int &y, int &x, char &direction, int score);

/* fill board vector from predefineds based on user selection */
void set_board(vector<vector<BoardItem>> &board);

/* return 1 on end */
int you_won(const vector<vector<BoardItem>> &board);


int get_random_valid_move(const vector<vector<BoardItem>> &board);

int get_score(const vector<vector<BoardItem>> &board);