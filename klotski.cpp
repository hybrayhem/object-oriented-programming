#include "klotski.h"

namespace BoardGame {
    Klotski::Klotski() {
        initialize();
    }

    void Klotski::initialize() {
        board = initialBoard;
        height = board.size();
        width = board[0].size();
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                board[i][j].setX(j);
                board[i][j].setY(i);
            }
            std::cout << std::endl;
        }
    }

    void Klotski::print(const std::string msg, bool overwrite) const {
        std::vector<int> colors = {41, 42, 43, 44, 45, 46, 47, 100, 101, 102, 103, 104, 105, 106, 107};

        if (overwrite) {
            for (int i = 0; i < 10; i++)
                std::cout << "\033[F";
        }

        std::cout << "\n";
        // std::cout << "\n       ";
        // for (size_t i = 0; i < width - 2; i++)
        //     std::cout << (char)(97 + i) << "  "; // print header row

        std::cout << "  ";
        for (size_t i = 0; i < width; i++)
            std::cout << "  *";
        if (msg != "") std::cout << "   (" << msg << ")";
        std::cout << std::endl;

        for (size_t i = 1; i < height - 1; i++) {
            std::cout << "   "; // print header column
            for (size_t j = 0; j < width; j++) {
                if (board[i][j].getID() == -1)
                    std::cout << "   ";
                else if (board[i][j].getID() == '*')
                    std::cout << " * ";
                else {
                    std::cout << "\033[" << colors[board[i][j].getID() % colors.size()] << "m " << board[i][j].getID() << " \033[m";
                    // std::cout << " " << board[i][j].getID() << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "     ";
        for (size_t i = 0; i < width - 2; i++)
            std::cout << "  *";
        std::cout << std::endl
                  << std::endl;
    }

    int Klotski::playUser(std::string command) {
        int id, success;
        char direction;
        if (!parseCommand(command, id, direction)) return 0;

        switch (direction) {
        case 'l':
            success = move_left(id);
            break;
        case 'r':
            success = move_right(id);
            break;
        case 'u':
            success = move_up(id);
            break;
        case 'd':
            success = move_down(id);
            break;
        }
        if (success == 0) std::cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements

        return success;
    }

    void Klotski::playAuto() {
        int id;
        std::vector<int> move;

        move = get_random_valid_move();

        id = move[0];
        std::cout << "Moving... " << id << "-"; // print last command done

        // perform slide
        switch (move[1]) {
        case 1:
            move_left(id);
            std::cout << "L";
            break;
        case 2:
            move_right(id);
            std::cout << "R";
            break;
        case 3:
            move_up(id);
            std::cout << "U";
            break;
        case 4:
            move_down(id);
            std::cout << "D";
            break;
        }

        // std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(25));
    }

    int Klotski::boardScore() {
        int x = 0, y = 0;
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                if (board[i][j].getID() == 1) {
                    x += board[i][j].getX();
                    y += board[i][j].getY();
                }
            }
        }
        x /= 4;
        y /= 4;
        return ((x - 2) * (x - 2) + (y - 5) * (y - 5));
    }

    int Klotski::parseCommand(std::string input, int &id, char &direction) {
        if (input.length() < 3) return 0;
        // convert char to int, '0','1','2' -> 0,1,2
        id = (int)(input[0]) - 48;

        direction = input[2];

        // command validation
        if (input[1] != '-' || id < 0 || id > 9 || !(direction == 'l' || direction == 'r' || direction == 'u' || direction == 'd')) {
            std::cerr << "Invalid input." << std::endl;
            return 0;
        }
        return 1;
    }

    int Klotski::getLeftIndex(int id) {
        for (size_t j = 0; j < width; j++) {
            for (size_t i = 0; i < height; i++) {
                if (board[i][j].getID() == id) {
                    return board[i][j].getX();
                }
            }
        }
        return -1;
    }
    bool Klotski::can_move_to_left(int id) {
        int leftIndex;
        if ((leftIndex = getLeftIndex(id)) == -1) return false;

        // check can move to up
        for (size_t i = 0; i < height; i++) {
            if (board[i][leftIndex].getID() == id) {
                if (leftIndex == 0 || board[i][leftIndex - 1].getID() != -1) {
                    return false;
                }
            }
        }
        return true;
    }

    int Klotski::getRightIndex(int id) {
        for (size_t j = 0; j < width; j++) {
            for (size_t i = 0; i < height; i++) {
                if (board[(height - 1) - i][(width - 1) - j].getID() == id) {
                    return board[(height - 1) - i][(width - 1) - j].getX();
                }
            }
        }
        return -1;
    }
    bool Klotski::can_move_to_right(int id) {
        int rightIndex;
        if ((rightIndex = getRightIndex(id)) == -1) return false;

        // check can move to up
        for (size_t i = 0; i < height; i++) {
            if (board[i][rightIndex].getID() == id) {
                if (rightIndex == (int)(width - 1) || board[i][rightIndex + 1].getID() != -1) {
                    return false;
                }
            }
        }
        return true;
    }

    int Klotski::getTopIndex(int id) {
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                if (board[i][j].getID() == id) {
                    return board[i][j].getY();
                }
            }
        }
        return -1;
    }
    bool Klotski::can_move_to_up(int id) {
        int topIndex;
        if ((topIndex = getTopIndex(id)) == -1) return false;

        // check can move to up
        for (size_t j = 0; j < width; j++) {
            if (board[topIndex][j].getID() == id) {
                if (topIndex == 0 || board[topIndex - 1][j].getID() != -1) {
                    return false;
                }
            }
        }
        return true;
    }

    int Klotski::getBottomIndex(int id) {
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                if (board[(height - 1) - i][(width - 1) - j].getID() == id) {
                    return board[(height - 1) - i][(width - 1) - j].getY();
                }
            }
        }
        return -1;
    }
    bool Klotski::can_move_to_down(int id) {
        int bottomIndex;
        if ((bottomIndex = getBottomIndex(id)) == -1) return false;

        // check can move to down
        for (size_t j = 0; j < width; j++) {
            if (board[bottomIndex][j].getID() == id) {
                if (bottomIndex == (int)(height - 1) || board[bottomIndex + 1][j].getID() != -1) {
                    return false;
                }
            }
        }
        return true;
    }

    int Klotski::move_left(int id) {
        if (can_move_to_left(id)) {
            for (size_t j = 0; j < width; j++) {
                for (size_t i = 0; i < height; i++) {
                    if (board[i][j].getID() == id) {
                        board[i][j].setID(-1);
                        board[i][j - 1].setID(id);
                    }
                }
            }
            return 1;
        }
        return 0;
    }

    int Klotski::move_right(int id) {
        if (can_move_to_right(id)) {
            for (size_t j = 0; j < width; j++) {
                for (size_t i = 0; i < height; i++) {
                    if (board[(height - 1) - i][(width - 1) - j].getID() == id) {
                        board[(height - 1) - i][(width - 1) - j].setID(-1);
                        board[(height - 1) - i][(width - 1) - j + 1].setID(id);
                    }
                }
            }
            return 1;
        }
        return 0;
    }

    int Klotski::move_up(int id) {
        if (can_move_to_up(id)) {
            for (size_t i = 0; i < height; i++) {
                for (size_t j = 0; j < width; j++) {
                    if (board[i][j].getID() == id) {
                        board[i][j].setID(-1);
                        board[i - 1][j].setID(id);
                    }
                }
            }
            return 1;
        }
        return 0;
    }

    int Klotski::move_down(int id) {
        if (can_move_to_down(id)) {
            for (size_t i = 0; i < height; i++) {
                for (size_t j = 0; j < width; j++) {
                    if (board[(height - 1) - i][(width - 1) - j].getID() == id) {
                        board[(height - 1) - i][(width - 1) - j].setID(-1);
                        board[(height - 1) - i + 1][(width - 1) - j].setID(id);
                    }
                }
            }
            return 1;
        }
        return 0;
    }

    int Klotski::sizeOfTile(int id) {
        int size = 0;
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                size += (board[i][j].getID() == id);
            }
        }
        return size;
    }

    std::vector<int> Klotski::get_random_valid_move() {
        /*std::vector<std::vector<int>> moves;

        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++) {
                std::vector<int> move;
                int tileSize = sizeOfTile(board[i][j].getID());

                if (can_move_to_left(board[i][j].getID())) { //[id, 1]
                    move.push_back(board[i][j].getID());
                    move.push_back(1);
                    moves.push_back(move);

                    // insert four times to random pool if tile size is two
                    // moves.insert(moves.end(), tileSize*2, move); //to equalize the probability of moving big and small tiles
                }
                if (can_move_to_right(board[i][j].getID())) { //[id, 2]
                    move.push_back(board[i][j].getID());
                    move.push_back(2);
                    moves.push_back(move);

                    // moves.insert(moves.end(), tileSize*2, move); //to equalize the probability of moving tiles
                }
                if (can_move_to_up(board[i][j].getID())) { //[id, 3]
                    move.push_back(board[i][j].getID());
                    move.push_back(3);
                    moves.push_back(move);

                    // moves.insert(moves.end(), tileSize, move); //to equalize the probability of moving tiles
                }
                if (can_move_to_down(board[i][j].getID())) { //[id, 4]
                    move.push_back(board[i][j].getID());
                    move.push_back(4);
                    moves.push_back(move);

                    // moves.insert(moves.end(), tileSize*tileSize, move); //to equalize the probability of moving tiles
                }
            }
        }

        int index = rand() % (int)(moves.size());
        return moves[index]; // random move from all possible moves*/
        int valid = 0, randomID, randomDirection;
        while (!valid) {
            randomID = rand() % 10;
            randomDirection = rand() % 4 + 1;

            switch (randomDirection) {
            case 1:
                valid = can_move_to_left(randomID);
                break;
            case 2:
                valid = can_move_to_right(randomID);
                break;
            case 3:
                valid = can_move_to_up(randomID);
                break;
            case 4:
                valid = can_move_to_down(randomID);
                break;
            }
        }
        std::vector<int> move;
        move.push_back(randomID);
        move.push_back(randomDirection);
        return move;
    }

    bool Klotski::endGame() {
        return (board[5][2].getID() == 1 && board[5][3].getID() == 1 && board[6][2].getID() == 1 && board[6][3].getID() == 1);
    }
}