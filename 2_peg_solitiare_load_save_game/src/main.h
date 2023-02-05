#include "boards.h"
#include <iostream>
#include <vector>

// print well formatted board
void print_board(const vector<vector<BoardItem>> &board);

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

// secure cin function that gets the selection for menu with a bullet-proof error handling
char get_selection(const string msg, char lower, char upper);

// read and parse move commands ex: B4-U
int get_command(int &y, int &x, char &direction, const vector<vector<BoardItem>> &board);

// fill board vector from predefineds based on user selection
void set_board(vector<vector<BoardItem>> &board);

// return 1 on no valid move
int you_won(const vector<vector<BoardItem>> &board);

// return move vector in {y, x, direction(1,2,3,4 equals l,r,u,d)}
vector<int> get_random_valid_move(const vector<vector<BoardItem>> &board);

// count pegs on board
int get_score(const vector<vector<BoardItem>> &board);

// load existing game from file
void load_game(char &gameType, vector<vector<BoardItem>> &board, string filename = "game.txt");

// save game to a file, gameType 1:human 2:computer
void save_game(int gameType, const vector<vector<BoardItem>> &board, string filename = "game.txt");

// show score and ask for save
void finish(const vector<vector<BoardItem>> &board, int gameType);