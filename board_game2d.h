#ifndef BOARD_GAME2D
#define BOARD_GAME2D

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

namespace BoardGame {
    class BoardGame2D {
    public:
        static void playVector(std::vector<BoardGame2D *> games);

        virtual void initialize() = 0;
        virtual void print(const std::string msg, bool overwrite) const = 0;
        friend std::ostream &operator<<(std::ostream &outs, const BoardGame2D &game);

        virtual int playUser(std::string command) = 0;
        virtual void playUser() final;
        virtual void playAuto() = 0;
        virtual void playAutoAll() final;

        virtual int boardScore() = 0;
        virtual bool endGame() = 0;

    private:
    };
}

#endif