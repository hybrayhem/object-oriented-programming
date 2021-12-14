#include <iostream>
#include <vector>


namespace BoardGame {
    class BoardGame2D {
    public:
        static void playVector(std::vector<BoardGame2D*> game);

        void initialize();
        void print();
        friend std::ostream &operator<<(std::ostream &outs, const BoardGame2D &game);
        
        virtual void playUser(std::string command);
        virtual void playUser() final;
        void playAuto();
        virtual void playAutoAll() final;

        int boardScore();
        bool endGame();

    private:
    };
}