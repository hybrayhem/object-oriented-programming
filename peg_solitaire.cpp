#include "peg_solitaire.h"

namespace BoardGame {
    PegSolitaire::PegSolitaire() {
        initialize();
    }

    void PegSolitaire::initialize() {
        board = board2;
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                board[i][j].setX(j);
                board[i][j].setY(i);
            }
            std::cout << std::endl;
        }
    }

    void PegSolitaire::print(const std::string msg, bool overwrite) const {
        if (overwrite) {
            for (int i = 0; i < 14; i++)
                std::cout << "\033[F";
        }

        std::cout << "\n   ";
        for (size_t i = 0; i < board[0].size(); i++)
            std::cout << (char)(97 + i) << " "; // print header row
        if (msg != "") std::cout << "(" << msg << ")";
        std::cout << std::endl;

        for (size_t i = 0; i < board.size(); i++) {
            std::cout << i + 1 << " "; // print header column
            for (size_t j = 0; j < board[0].size(); j++) {
                switch (board[i][j].getType()) {
                case Cell::cell_t::EMPTY:
                    std::cout << "  ";
                    break;
                case Cell::cell_t::PEG:
                    std::cout << " P";
                    break;
                case Cell::cell_t::DOT:
                    std::cout << " .";
                    break;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int PegSolitaire::playUser(std::string command) {
        int y, x, success;
        char direction;
        if (!parseCommand(command, y, x, direction)) return 0;

        switch (direction) {
        case 'l':
            success = move_left(board[y][x]);
            break;
        case 'r':
            success = move_right(board[y][x]);
            break;
        case 'u':
            success = move_up(board[y][x]);
            break;
        case 'd':
            success = move_down(board[y][x]);
            break;
        }
        if (success == 0) std::cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements

        return success;
    }

    void PegSolitaire::playAuto() {
        int y, x, success;
        std::vector<int> move;

        move = get_random_valid_move();

        y = move[0];
        x = move[1];
        std::cout << "Moving... " << (char)(x + 65) << y + 1 << "-"; // print last command done

        switch (move[2]) {
        case 1:
            success = move_left(board[y][x]);
            std::cout << "L";
            break;
        case 2:
            success = move_right(board[y][x]);
            std::cout << "R";
            break;
        case 3:
            success = move_up(board[y][x]);
            std::cout << "U";
            break;
        case 4:
            success = move_down(board[y][x]);
            std::cout << "D";
            break;
        }
        std::cout << "\n\n";

        if (!success) std::cerr << "\n> OOPS, something went wrong!\n\n"; // for invalid movements

        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(100));
    }

    int PegSolitaire::boardScore() {
        int peg = 0;

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j].getType() == PegSolitaire::Cell::cell_t::PEG) peg++;
            }
        }
        return peg;
    }

    int PegSolitaire::parseCommand(std::string input, int &y, int &x, char &direction) {
        if (input.length() < 4) return 0;
        // convert char to int, 'a','b','c' -> 0,1,2
        x = (int)(input[0]) - 97;

        // convert char to int, '1','2','3' -> 1,2,3
        y = (int)(input[1]) - 48;
        y--;

        direction = input[3];

        // command validation
        if (input[2] != '-' || x < 0 || y < 0 || y >= (int)(board.size()) || x >= (int)(board[0].size()) || !(direction == 'l' || direction == 'r' || direction == 'u' || direction == 'd')) {
            std::cerr << "Invalid input." << std::endl;
            return 0;
        }
        return 1;
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
            return 1;
        }
        return 0;
    }

    int PegSolitaire::move_right(Cell cell) {
        if (can_move_to_right(cell)) {
            board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
            board[cell.getY()][cell.getX() + 1].setType(Cell::cell_t::DOT);
            board[cell.getY()][cell.getX() + 2].setType(Cell::cell_t::PEG);
            return 1;
        }
        return 0;
    }

    int PegSolitaire::move_up(Cell cell) {
        if (can_move_to_up(cell)) {
            board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
            board[cell.getY() - 1][cell.getX()].setType(Cell::cell_t::DOT);
            board[cell.getY() - 2][cell.getX()].setType(Cell::cell_t::PEG);
            return 1;
        }
        return 0;
    }

    int PegSolitaire::move_down(Cell cell) {
        if (can_move_to_down(cell)) {
            board[cell.getY()][cell.getX()].setType(Cell::cell_t::DOT);
            board[cell.getY() + 1][cell.getX()].setType(Cell::cell_t::DOT);
            board[cell.getY() + 2][cell.getX()].setType(Cell::cell_t::PEG);
            return 1;
        }
        return 0;
    }

    std::vector<int> PegSolitaire::get_random_valid_move() {
        std::vector<std::vector<int>> moves;

        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                std::vector<int> move;
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

    bool PegSolitaire::endGame() {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if ((can_move_to_left(board[i][j])) ||
                    (can_move_to_right(board[i][j])) ||
                    (can_move_to_up(board[i][j])) ||
                    (can_move_to_down(board[i][j]))) {
                    return false;
                }
            }
        }
        return true;
    }
}