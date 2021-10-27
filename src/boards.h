#include <vector>
using namespace std;

enum class BoardItem {
    PEG,
    DOT,
    EMPTY
};

/*
- - P P P - -
- P P P P P -
P P P . P P P
P P P P P P P
P P P P P P P
- P P P P P -
- - P P P - -
*/
const vector<vector<BoardItem>> board1 = {
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::DOT, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
};

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
const vector<vector<BoardItem>> board2 = {
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::DOT, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
};

/*
- - P P P - - -
- - P P P - - -
- - P P P - - -
P P P P P P P P
P P P . P P P P
P P P P P P P P
- - P P P - - -
- - P P P - - -
*/
const vector<vector<BoardItem>> board3 = {
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::DOT, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
};

/*
- - P P P - -
- - P P P - -
P P P P P P P
P P P . P P P
P P P P P P P
- - P P P - -
- - P P P - -
*/
const vector<vector<BoardItem>> board4 = {
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::DOT, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
};

/*
- - - - P - - - -
- - - P P P - - -
- - P P P P P - -
- P P P P P P P -
P P P P . P P P P
- P P P P P P P -
- - P P P P P - -
- - - P P P - - -
- - - - P - - - -
*/
const vector<vector<BoardItem>> board5 = {
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::DOT, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
    {BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
};

/*
. - - - -
P P - - -
P P P - -
P P P P -
P P P P P
*/
const vector<vector<BoardItem>> board6 = {
    {BoardItem::DOT, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::EMPTY},
    {BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG, BoardItem::PEG},
};
