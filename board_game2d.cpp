#include "board_game2d.h"

namespace BoardGame {
    void BoardGame2D::playAutoSmart() {
        std::vector<std::string> moves;
        std::string bestMove;
        int bestScore;

        moves = nextMoves();

        bestMove = moves[0];
        bestScore = nextScore(bestMove);
        for(size_t i = 1; i < moves.size(); i++){
            if(nextScore(moves[i]) > bestScore){
                bestScore = nextScore(moves[i]);
                bestMove = moves[i];
            }
        }

        std::cout << "Moving... " << bestMove << "." << std::endl;
        playUser(bestMove);
    }

    void BoardGame2D::playVector(std::vector<BoardGame2D *> games) {
        for (size_t i = 0; i < games.size(); i++) {
            games[i]->playAutoAll();
        }
    }

    void BoardGame2D::playUser() {
        int success;
        std::string input;

        do {
            std::cout << "Enter your command(c2-u, g6-l, b1-d, c3-l or tile number 0-r, 1-d, 7-u): ";
            getline(std::cin, input);
            success = playUser(input);
        } while (success == 0);
        print("after " + input, false);
    }

    void BoardGame2D::playAutoAll() {
        int counter = 0;

        // std::cout << "AUTO ALL" << std::endl;
        for (int i = 0; i < 15; i++)
            std::cout << std::endl;
        while (!endGame()) {
            playAuto();
            print("", true);
            counter++;
        }
        std::cout << "Solved in " << counter << " moves." << std::endl;
        std::cout << "Board score: " << boardScore() << std::endl;
    }

    std::ostream &operator<<(std::ostream &outs, const BoardGame2D &game) {
        game.print("", false);
        return outs;
    }
}