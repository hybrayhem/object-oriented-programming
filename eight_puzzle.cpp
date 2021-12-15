#include "eight_puzzle.h"

namespace BoardGame {
    EightPuzzle::EightPuzzle() {
        initialize();
    }

    void EightPuzzle::initialize() {
        char direction;
        int indexA, indexB, axis; // random numbers
        float difficulty = 1;     // 1 is easy, 2 is middle, 3 is hard;  determines number of movement to solve puzzle

        // create puzzle board
        puzzle = initialPuzzle;
        spaceA = N - 1;
        spaceB = N - 1; // last square is space

        // makes random movements on board, board is solvable in all conditions and difficulty is adjustable
        for (int i = rand() % 2; i < N * N * difficulty; i++) // start from random binary position for axis
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
            for (int i = 0; i < 13; i++)
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
        if (success == 0) std::cerr << "\n> OOPS! I can't move to that direction!\n\n"; // for invalid movements

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
        int score = 0;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                score += (puzzle[i][j] != initialPuzzle[i][j]);
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

    int EightPuzzle::move_left(int a, int b) {
        int i;

        if (a == spaceA && b > spaceB) {
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

        if (a == spaceA && b < spaceB) {
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

        if (b == spaceB && a > spaceA) {
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

        if (b == spaceB && a < spaceA) {
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

    bool EightPuzzle::endGame() {
        int thisItem, nextItem;

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                if (i == N - 1 && j == N - 1) break;

                /* set thisItem and nextItem value */
                thisItem = puzzle[i][j];
                if (j != N - 1)
                    nextItem = puzzle[i][j + 1];
                else
                    nextItem = puzzle[i + 1][0];

                if (thisItem == -1 || nextItem == -1) continue;
                /* difference between numbers must be 1 */
                if (nextItem - thisItem != 1) {
                    return false; /* no win */
                }
            }
        }
        return true; /* win */
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
}