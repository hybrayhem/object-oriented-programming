#include "eight_puzzle.h"

namespace BoardGame {
    EightPuzzle::EightPuzzle() {
        initialize();
    }

    void EightPuzzle::initialize() {
        char direction;
        int indexA, indexB, axis; // random numbers
        float difficulty = 1;     // 1 is easy, 2 is middle, 3 is hard;  determines number of movement to solve puzzle

        /* create puzzle board */
        int x = 1;
        for (size_t i = 0; i < N; i++) {
            std::vector<int> row;
            for (size_t j = 0; j < N; j++) {
                row.push_back(x);
                x++;
            }
            puzzle.push_back(row);
        }
        spaceA = N - 1;
        spaceB = N - 1;
        puzzle[spaceA][spaceB] = -1; /* last square is space */

        // makes random movements on board, board is solvable in all conditions and difficulty is adjustable
        for (int i = rand() % 2; i < 3 /*N * N * difficulty*/; i++) // start from random binary position for axis
        {
            axis = i % 2; // horizontal and vertical respectively

            // random move in horizontal
            if (axis == 0) {
                indexA = spaceA;
                indexB = spaceB;

                // select an random item from same row with space
                while (indexB == spaceB) {
                    indexB = rand() % N;
                }

                // determine psssible slide direction
                if (indexB > spaceB)
                    direction = 'l';
                else if (indexB < spaceB)
                    direction = 'r';

            } else {
                indexB = spaceB;
                indexA = spaceA;

                // select an random item from same column with space
                while (indexA == spaceA) {
                    indexA = rand() % N;
                }

                // determine psssible slide direction
                if (indexA > spaceA)
                    direction = 'u';
                else if (indexA < spaceA)
                    direction = 'd';
            }

            // perform slide
            switch (direction) {
            case 'l':
                move_left(indexA, indexB);
                break;
            case 'r':
                move_right(indexA, indexB);
                break;
            case 'u':
                move_up(indexA, indexB);
                break;
            case 'd':
                move_down(indexA, indexB);
                break;
            }
        }
    }

    void EightPuzzle::print(const std::string msg, bool overwrite) const {
        if (overwrite) {
            for (int i = 0; i < 15; i++)
                std::cout << "\033[F";
        }

        /* header row */
        std::cout << "\n\n\n     ";
        for (int i = 0; i < N; i++) {
            if (i + 1 < 10)
                std::cout << "  [" << (char)(97 + i) << "] ";
            else
                std::cout << " [" << (char)(97 + i) << "] ";
        }
        if (msg != "") std::cout << "  (" << msg << ")";
        std::cout << "\n\n     ";

        /* top line */
        for (int j = 0; j < N * 3 + 1; j++)
            std::cout << "* ";
        std::cout << std::endl;

        for (int i = 0; i < N; i++) {
            /* row numbers */
            if (i + 1 < 10)
                std::cout << "[" << i + 1 << "]  * ";
            else
                std::cout << "[" << i + 1 << "] * ";

            /* board items */
            for (int j = 0; j < N; j++) {
                if (puzzle[i][j] == -1) {
                    std::cout << " □  * "; /* space item */
                } else {
                    printf(" %-3d* ", puzzle[i][j]);
                }
            }

            /* bottom lines */
            std::cout << "\n     ";
            for (int j = 0; j < N * 3 + 1; j++)
                std::cout << "* ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int EightPuzzle::playUser(std::string command) {
        int a, b, success;
        char direction;
        if (!parseCommand(command, a, b, direction)) return 0;

        switch (direction) {
        case 'l':
            success = move_left(a, b);
            break;
        case 'r':
            success = move_right(a, b);
            break;
        case 'u':
            success = move_up(a, b);
            break;
        case 'd':
            success = move_down(a, b);
            break;
        }
        // if (success == 0) std::cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements

        return success;
    }

    void EightPuzzle::playAuto() {
        int a, b;
        std::vector<int> move;

        move = get_random_valid_move();

        a = move[0];
        b = move[1];
        std::cout << "Moving... " << (char)(b + 65) << a + 1 << "-"; // print last command done

        // perform slide
        switch (move[2]) {
        case 1:
            move_left(a, b);
            std::cout << "L";
            break;
        case 2:
            move_right(a, b);
            std::cout << "R";
            break;
        case 3:
            move_up(a, b);
            std::cout << "U";
            break;
        case 4:
            move_down(a, b);
            std::cout << "D";
            break;
        }

        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::nanoseconds(25));
    }

    int EightPuzzle::boardScore() {
        int score = 0, tile = 1; // tile num one to fiveteen
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                if (puzzle[i][j] != -1) score += abs(puzzle[i][j] - tile);
                tile++;
            }
        }
        return score;
    }

    int EightPuzzle::parseCommand(std::string input, int &a, int &b, char &direction) {
        if (input.length() < 4) return 0;
        // convert char to int, 'a','b','c' -> 0,1,2
        b = (int)(input[0]) - 97;
        // convert char to int, '1','2','3' -> 0,1,2
        a = (int)(input[1]) - 49;

        direction = input[3];

        // command validation
        if (input[2] != '-' || a < 0 || b < 0 || a >= N || b >= N || !(direction == 'l' || direction == 'r' || direction == 'u' || direction == 'd')) {
            std::cerr << "Invalid input." << std::endl;
            return 0;
        }
        return 1;
    }

    bool EightPuzzle::can_move_to_left(int a, int b) {
        return (a == spaceA && b > spaceB);
    }
    bool EightPuzzle::can_move_to_right(int a, int b) {
        return (a == spaceA && b < spaceB);
    }
    bool EightPuzzle::can_move_to_up(int a, int b) {
        return (b == spaceB && a > spaceA);
    }
    bool EightPuzzle::can_move_to_down(int a, int b) {
        return (b == spaceB && a < spaceA);
    }

    int EightPuzzle::move_left(int a, int b) {
        int i;

        if (can_move_to_left(a, b)) {
            /* slide every item left until reach space */
            for (i = (spaceB) + 1; i <= b; i++) {
                puzzle[a][i - 1] = puzzle[a][i];
            }
            puzzle[a][b] = -1; /* set start point as space */
            /* update space location */
            spaceA = a;
            spaceB = b;
            return 1;
        } else {
            return 0;
        }
    }

    int EightPuzzle::move_right(int a, int b) {
        int i;

        if (can_move_to_right(a, b)) {
            for (i = (spaceB)-1; i >= b; i--) {
                puzzle[a][i + 1] = puzzle[a][i];
            }
            puzzle[a][b] = -1;
            spaceA = a;
            spaceB = b;
            return 1;
        } else {
            return 0;
        }
    }

    int EightPuzzle::move_up(int a, int b) {
        int i;

        if (can_move_to_up(a, b)) {
            /* slide every item up until reach space */
            for (i = (spaceA) + 1; i <= a; i++) {
                puzzle[i - 1][b] = puzzle[i][b];
            }
            puzzle[a][b] = -1; /* set start point as space */
            /* update space location */
            spaceA = a;
            spaceB = b;
            return 1;
        } else {
            return 0;
        }
    }

    int EightPuzzle::move_down(int a, int b) {
        int i;

        if (can_move_to_down(a, b)) {
            for (i = (spaceA)-1; i >= a; i--) {
                puzzle[i + 1][b] = puzzle[i][b];
            }
            puzzle[a][b] = -1;
            spaceA = a;
            spaceB = b;
            return 1;
        } else {
            return 0;
        }
    }

    std::vector<int> EightPuzzle::get_random_valid_move() {
        std::vector<int> move;
        int direction, indexA, indexB, axis;

        int i = rand() % 2; // start from random binary position for axis

        axis = i % 2; // horizontal and vertical respectively

        // random move in horizontal
        if (axis == 0) {
            indexA = spaceA;
            indexB = spaceB;

            // select an random item from same row with space
            while (indexB == spaceB) {
                indexB = rand() % N;
            }

            // determine psssible slide direction
            if (indexB > spaceB)
                direction = 1;
            else if (indexB < spaceB)
                direction = 2;

        } else {
            indexB = spaceB;
            indexA = spaceA;

            // select an random item from same column with space
            while (indexA == spaceA) {
                indexA = rand() % N;
            }

            // determine psssible slide direction
            if (indexA > spaceA)
                direction = 3;
            else if (indexA < spaceA)
                direction = 4;
        }

        move.push_back(indexA);
        move.push_back(indexB);
        move.push_back(direction);

        return move;
    }

    bool EightPuzzle::endGame() {
        return (boardScore() == 0);
    }

    std::vector<std::string> EightPuzzle::nextMoves() {
        std::vector<std::string> moves;

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                std::string move;
                move = (char)(j + 97) + std::to_string(i + 1) + "-";
                if ((can_move_to_left(i, j))) {
                    move = move + "l";
                    moves.push_back(move);
                }
                if ((can_move_to_right(i, j))) {
                    move = move + "r";
                    moves.push_back(move);
                }
                if ((can_move_to_up(i, j))) {
                    move = move + "u";
                    moves.push_back(move);
                }
                if ((can_move_to_down(i, j))) {
                    move = move + "d";
                    moves.push_back(move);
                }
                // std::cout << "move: " << move << std::endl;
            }
        }
        return moves;
    }

    int EightPuzzle::nextScore(std::string move) {
        int score;
        // print("nextscore", false);
        std::vector<std::vector<int>> tempPuzzle;
        for (size_t i = 0; i < N; i++) {
            std::vector<int> row;
            for (size_t j = 0; j < N; j++) {
                row.push_back(puzzle[i][j]);
            }
            tempPuzzle.push_back(row);
        }

        playUser(move);
        score = boardScore();
        // print("nextscore", false);

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                puzzle[i][j] = tempPuzzle[i][j];
            }
        }

        return score;
    }
}