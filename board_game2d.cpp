#include "board_game2d.h"

namespace BoardGame {

    void BoardGame2D::playUser() {
        int success;
        std::string input;

        do {
            std::cout << "Enter your command(c2-u, g6-l, b1-d, c3-l): ";
            getline(std::cin, input);
            success = playUser(input);
        } while (success == 0);
        print("after " + input);
    }

    void BoardGame2D::playAutoAll() {
    }

    std::ostream &operator<<(std::ostream &outs, const BoardGame2D &game) {
        game.print("");
        return outs;
    }
}