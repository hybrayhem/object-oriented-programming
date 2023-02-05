#ifndef KLOTSKI
#define KLOTSKI

#include "board_game2d.h"

namespace BoardGame {
    class Klotski : public BoardGame2D {
    public:
        Klotski();

        class Block {
            int x, y;

        public:
            // enum block_t {
            //     TILE,
            //     SPACE,
            //     EMPTY
            // };
            // block_t type;

            int id;
            Block(int tileID) : id(tileID){};

            int getX() {
                return x;
            }

            int getY() {
                return y;
            }

            void setX(int _x) {
                x = _x;
            }

            void setY(int _y) {
                y = _y;
            }

            int getID() const {
                return id;
            }

            void setID(int tileID) {
                id = tileID;
            }
        };

        void initialize();                                       // creates random sliding puzzle 2d array
        void print(const std::string msg, bool overwrite) const; // print well-formatted puzzle

        int playUser(std::string command); // certain move
        void playAuto();                   // random computer move

        int boardScore(); // distance between current puzzle and solved, less is better

    private:
        std::vector<std::vector<Block>> board;
        size_t height, width;

        int parseCommand(std::string input, int &id, char &direction); // read and parse move commands ex: 1-u, 2-l, 4-d

        int getLeftIndex(int id);      // left corner of tile
        bool can_move_to_left(int id); // check the item with id can move to left

        int getRightIndex(int id);      // right corner of tile
        bool can_move_to_right(int id); // check the item with id can move to right

        int getTopIndex(int id);     // upper corner of tile
        bool can_move_to_up(int id); // check the item with id can move to up

        int getBottomIndex(int id);    // bottom corner of tile
        bool can_move_to_down(int id); // check the item with id can move to down

        // move items with id
        int move_left(int id);
        int move_right(int id);
        int move_up(int id);
        int move_down(int id);

        bool endGame(); // checks win status

        // return move vector in {a, b, direction(1,2,3,4 equals l,r,u,d)}
        int sizeOfTile(int id);
        std::vector<int> get_random_valid_move();

        /*

        * * * * * 
       * 0 1 1 2 *
       * 0 1 1 2 *
       * 3 4 4 5 *
       * 3 6 7 5 *
       * 8     9 *
       * *     * *
         * * * * 
        
        */
        // Klotski "forget me not" board
        const std::vector<std::vector<Block>> initialBoard = {
            {Block('*'), Block('*'), Block('*'), Block('*'), Block('*'), Block('*')},
            {Block('*'), Block(0), Block(1), Block(1), Block(2), Block('*')},
            {Block('*'), Block(0), Block(1), Block(1), Block(2), Block('*')},
            {Block('*'), Block(3), Block(4), Block(4), Block(5), Block('*')},
            {Block('*'), Block(3), Block(6), Block(7), Block(5), Block('*')},
            {Block('*'), Block(8), Block(-1), Block(-1), Block(9), Block('*')},
            {Block('*'), Block('*'), Block(-1), Block(-1), Block('*'), Block('*')},
            {Block('*'), Block('*'), Block('*'), Block('*'), Block('*'), Block('*')},
        };
    };
}

#endif