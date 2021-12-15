#include "board_game2d.h"

namespace BoardGame {
    void playVector(std::vector<BoardGame2D *> games) {
        for (size_t i = 0; i < games.size(); i++) {
            games[i]->playAutoAll();
        }
    }

    void BoardGame2D::playUser() {
        int success;
        std::string input;

        do {
            std::cout << "Enter your command(c2-u, g6-l, b1-d, c3-l): ";
            getline(std::cin, input);
            success = playUser(input);
        } while (success == 0);
        print("after " + input, false);
    }

    void BoardGame2D::playAutoAll() {
        std::cout << "AUTO ALL" << std::endl;
        for (int i = 0; i < 15; i++)
            std::cout << std::endl;
        while (!endGame()) {
            playAuto();
            print("", true);
        }
    }

    std::ostream &operator<<(std::ostream &outs, const BoardGame2D &game) {
        game.print("", false);
        return outs;
    }
}