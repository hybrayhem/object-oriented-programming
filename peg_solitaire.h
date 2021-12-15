#ifndef PEG_SOLITAIRE
#define PEG_SOLITAIRE

#include "board_game2d.h"

namespace BoardGame {
    class PegSolitaire : public BoardGame2D {
    public:
        PegSolitaire(); // default constructor

        class Cell {
            int x, y;

        public:
            enum cell_t {
                PEG,
                DOT,
                EMPTY
            };
            cell_t type;

            Cell(cell_t cellType) : type(cellType){};
            Cell(int x, int y) : x(x), y(y){};

            inline int getX() {
                return x;
            }

            inline int getY() {
                return y;
            }

            void setX(int _x) {
                x = _x;
            }

            void setY(int _y) {
                y = _y;
            }

            cell_t getType() const {
                return type;
            }

            void setType(cell_t cellType) {
                type = cellType;
            }
        };

        void initialize(); // set board and x,y values of cells
        void print(const std::string msg) const;
        friend std::ostream &operator<<(std::ostream &outs, const PegSolitaire &game);

        int playUser(std::string command); // certain move
        void playAuto();                    // random computer move

        int boardScore();

    private:
        std::vector<std::vector<Cell>> board;

        int parseCommand(std::string input, int &y, int &x, char &direction); // read and parse move commands ex: B4-U

        bool can_move_to_left(Cell cell);  // check the peg at board[y][x] can move to left
        bool can_move_to_right(Cell cell); // check the peg at board[y][x] can move to right
        bool can_move_to_up(Cell cell);    // check the peg at board[y][x] can move to up
        bool can_move_to_down(Cell cell);  // check the peg at board[y][x] can move to down
        int move_left(Cell cell);          // take the target peg and move two square left over another peg
        int move_right(Cell cell);         // take the target peg and move two square right over another peg
        int move_up(Cell cell);            // take the target peg and move two square up over another peg
        int move_down(Cell cell);          // take the target peg and move two square down over another peg
        bool endGame();

        // return move vector in {y, x, direction(1,2,3,4 equals l,r,u,d)}
        std::vector<int> get_random_valid_move();

        /*
        - - - P P P - - -
        - - - P P P - - -
        - - - P P P - - -
        P P P P P P P P P
        P P P P . P P P P
        P P P P P P P P P
        - - - P P P - - -
        - - - P P P - - -
        - - - P P P - - -
        */
        const std::vector<std::vector<Cell>> board2 = {
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
            {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
            {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::DOT), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
            {Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG)},
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
            {Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::PEG), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY), Cell(Cell::cell_t::EMPTY)},
        };
    };
}

#endif