#include "peg_solitaire.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// secure cin function that gets the selection for menu with a bullet-proof error handling
char get_selection(const string msg, char lower, char upper) {
    int flag = 0;
    char selection = 0;

    while (!flag) {
        if (msg[0] != '\0') cout << msg;
        cin >> selection;
        cin.ignore(80, '\n'); // remove unnecessary characters
        if (selection < lower || selection > upper) {
            cout << "TRY AGAIN" << endl;
            continue;
        }
        flag = 1;
    }
    return selection;
}

int PegSolitaire::totalPeg = 0;
/* -------------------------------------------------------------------------- */
/*                  DRIVER PROGRAM TO TEST PegSolitaire CLASS                 */
/* -------------------------------------------------------------------------- */
int main() {
    string filename;

    // ---------------------------- TEST CONSTRUCTORS --------------------------- //
    // Initialize object with default constructor
    cout << "Initialize object with default constructor." << endl;
    PegSolitaire pegame1;
    pegame1.print_board("pegame1");

    // Initialize object with board type
    cout << "Initialize object with board type 2" << endl;
    PegSolitaire pegame2('2');
    pegame2.print_board("pegame2");

    // Initialize object with board type
    cout << "Initialize object with board type 3" << endl;
    PegSolitaire pegame3('3');
    pegame3.print_board("pegame3");

    // Initialize object with board type
    cout << "Initialize object with board type input" << endl;
    char selection = get_selection("> Select the board 1-6: ", '1', '6');
    PegSolitaire pegame4(selection);
    pegame4.print_board("pegame4");

    // Initialize object with loading from file
    cout << "Initialize object with loading from file" << endl;
    cout << "Enter file name to load(ex: arbitrary.txt): ";
    getline(cin, filename);
    cout << endl;
    PegSolitaire pegame5(filename);
    pegame5.print_board("pegame5");


    // --------------------- GET NUMBER OF PEGS, EMPTY, DOTS -------------------- //
    cout << "Number of pegs: " << pegame1.getNumberOfPegs() << ", empty: " << pegame1.getNumberOfEmpty() << ", outs: " << pegame1.getNumberOfPegsOut() << " in pegame1" << endl;
    cout << "Number of pegs: " << pegame2.getNumberOfPegs() << ", empty: " << pegame2.getNumberOfEmpty() << ", outs: " << pegame2.getNumberOfPegsOut() << " in pegame2" << endl;
    cout << "Number of pegs: " << pegame3.getNumberOfPegs() << ", empty: " << pegame3.getNumberOfEmpty() << ", outs: " << pegame3.getNumberOfPegsOut() << " in pegame3" << endl;
    cout << "Number of pegs: " << pegame4.getNumberOfPegs() << ", empty: " << pegame4.getNumberOfEmpty() << ", outs: " << pegame4.getNumberOfPegsOut() << " in pegame4" << endl;
    cout << "Number of pegs: " << pegame5.getNumberOfPegs() << ", empty: " << pegame5.getNumberOfEmpty() << ", outs: " << pegame5.getNumberOfPegsOut() << " in pegame5" << endl << endl << endl;
    

    // ----------------------------- FILE OPERATIONS ----------------------------- //
    // Save object to file
    cout << "Enter file name to save pegame5(ex: save.txt): ";
    getline(cin, filename);
    cout << endl;
    pegame5.save_game(filename);
    cout << "Board saved to file: " << filename << endl;
    pegame5.print_board("pegame5");

    cout << "STATIC FUNCTION AND VARIABLES:" << endl;
    cout << "Total number of pegs in all boards = " << PegSolitaire::getTotalNumberOfPegs() << endl;
    cout << "Compare number of pegs of pegame1 and pegame2 = " << (PegSolitaire::compareGames(pegame1, pegame2) ? "First greater" : "Second greater") << endl;


    // ----------------------------- PLAY FUNCTIONS ----------------------------- //
    //PLAY 1
    cout << "PLAY FUNCTION 1\n\n";
    pegame1.print_board("pegame1");
    pegame1.play();
    pegame1.print_board("pegame1 after play");

    //PLAY 3
    cout << "PLAY FUNCTION 2\n\n";
    pegame2.print_board("pegame2");
    pegame2.play(PegSolitaire::Cell(4, 2), 'D');
    pegame2.print_board("pegame2 after play E3-D");

    //PLAY 2
    cout << "PLAY FUNCTION 2 with USER INPUT\n\n";
    pegame3.print_board("pegame3");
    int x, y, success;
    char direction;
    do {
        cout << "Enter your command(C2-L, A5-U): ";
        success = pegame3.getCommand(y, x, direction);
    } while (success == 0);
    pegame3.play(PegSolitaire::Cell(x, y), direction);
    pegame3.print_board("pegame3");

    //PLAYGAME
    pegame4.print_board("pegame4");
    cout << "PLAYGAME will play on pegame4 until end." << endl;
    get_selection("> Press 'e' to see PlayGame in action: ", 'e', 'e');
    cout << "PlayGame function\n\n";
    pegame4.playGame();
    cout << "pegame4 after PlayGame" << endl << endl;

    cout << "SAVING pegame4 to save.txt..." << endl;
    pegame4.save_game();
    return 0;
}