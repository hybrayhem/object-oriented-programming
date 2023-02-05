package Pegame;

import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Component;
import java.awt.Color;

public class PegSolitaireGame {
        CellType[][] board;

        public PegSolitaireGame(int id) {
                board = boards[id];

        }

        public PegSolitaireGame() {
                board = board1;
        }

        private boolean canMove2Left(int y, int x) {
                return (x - 2 >= 0) && (board[y][x] == CellType.PEG
                                && board[y][x - 1] == CellType.PEG
                                && board[y][x - 2] == CellType.DOT);
        }

        // private boolean canMove2Left(int y, int x, JButton[][] buttons) {
        // return (x - 2 >= 0) && (buttons[y][x].getBackground() == Color.BLUE
        // && buttons[y][x - 1].getBackground() == Color.BLUE
        // && buttons[y][x - 2].getBackground() == Color.GRAY);
        // }

        private boolean canMove2Right(int y, int x) {
                return (x + 2 < (int) (board[0].length))
                                && (board[y][x] == CellType.PEG && board[y][x + 1] == CellType.PEG
                                                && board[y][x + 2] == CellType.DOT);
        }

        private boolean canMove2Up(int y, int x) {
                return (y - 2 >= 0)
                                && (board[y][x] == CellType.PEG && board[y - 1][x] == CellType.PEG
                                                && board[y - 2][x] == CellType.DOT);
        }

        private boolean canMove2Down(int y, int x) {
                return (y + 2 < (int) (board.length))
                                && (board[y][x] == CellType.PEG && board[y + 1][x] == CellType.PEG
                                                && board[y + 2][x] == CellType.DOT);
        }

        boolean moveLeft(int y, int x, JButton[][] buttons) { // . P P -> P . .
                if (canMove2Left(y, x)) {
                        board[y][x] = CellType.DOT;
                        board[y][x - 1] = CellType.DOT;
                        board[y][x - 2] = CellType.PEG;
                        
                        // JButton tempDot1 = new JButton();
                        // tempDot1.addActionListener(buttons[y][x - 2].getActionListeners()[0]);
                        // tempDot1.setBackground(Color.GRAY);
                        // tempDot1.setActionCommand(buttons[y][x].getActionCommand());
                        
                        // JButton tempDot2 = new JButton();
                        // tempDot2.addActionListener(buttons[y][x - 2].getActionListeners()[0]);
                        // tempDot2.setBackground(Color.GRAY);
                        // tempDot2.setActionCommand(buttons[y][x - 1].getActionCommand());
                        
                        // JButton tempPeg = new JButton();
                        // tempPeg.addActionListener(buttons[y][x].getActionListeners()[0]);
                        // tempPeg.setBackground(Color.BLUE);
                        // tempPeg.setActionCommand(buttons[y][x - 2].getActionCommand());

                        // buttons[y][x] = tempDot1;
                        // buttons[y][x - 1] = tempDot1;
                        // buttons[y][x - 2] = tempPeg;
                        buttons[y][x].setBackground(Color.GRAY);
                        buttons[y][x - 1].setBackground(Color.GRAY);
                        buttons[y][x - 2].setBackground(Color.BLUE);

                        return true;
                }
                return false;
        }

        boolean moveRight(int y, int x, JButton[][] buttons) {
                if (canMove2Right(y, x)) {
                        board[y][x] = CellType.DOT;
                        board[y][x + 1] = CellType.DOT;
                        board[y][x + 2] = CellType.PEG;

                        buttons[y][x].setBackground(Color.GRAY);
                        buttons[y][x + 1].setBackground(Color.GRAY);
                        buttons[y][x + 2].setBackground(Color.BLUE);
                        return true;
                }
                return false;
        }

        boolean moveUp(int y, int x, JButton[][] buttons) {
                if (canMove2Up(y, x)) {
                        board[y][x] = CellType.DOT;
                        board[y - 1][x] = CellType.DOT;
                        board[y - 2][x] = CellType.PEG;

                        buttons[y][x].setBackground(Color.GRAY);
                        buttons[y - 1][x].setBackground(Color.GRAY);
                        buttons[y - 2][x].setBackground(Color.BLUE);
                        return true;
                }
                return false;
        }

        boolean moveDown(int y, int x, JButton[][] buttons) {
                if (canMove2Down(y, x)) {
                        board[y][x] = CellType.DOT;
                        board[y + 1][x] = CellType.DOT;
                        board[y + 2][x] = CellType.PEG;

                        buttons[y][x].setBackground(Color.GRAY);
                        buttons[y + 1][x].setBackground(Color.GRAY);
                        buttons[y + 2][x].setBackground(Color.BLUE);
                        return true;
                }
                return false;
        }

        // Pre-defined boards
        enum CellType {
                PEG,
                DOT,
                EMPTY
        }

        /*
         * - - P P P - -
         * - P P P P P -
         * P P P . P P P
         * P P P P P P P
         * P P P P P P P
         * - P P P P P -
         * - - P P P - -
         */
        private static final CellType[][] board1 = {
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.DOT, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
        };

        /*
         * - - - P P P - - -
         * - - - P P P - - -
         * - - - P P P - - -
         * P P P P P P P P P
         * P P P P . P P P P
         * P P P P P P P P P
         * - - - P P P - - -
         * - - - P P P - - -
         * - - - P P P - - -
         */
        private static final CellType[][] board2 = {
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.DOT, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.PEG },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
        };

        /*
         * - - P P P - - -
         * - - P P P - - -
         * - - P P P - - -
         * P P P P P P P P
         * P P P . P P P P
         * P P P P P P P P
         * - - P P P - - -
         * - - P P P - - -
         */
        private static final CellType[][] board3 = {
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.DOT, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY,
                                        CellType.EMPTY },
        };

        /*
         * - - P P P - -
         * - - P P P - -
         * P P P P P P P
         * P P P . P P P
         * P P P P P P P
         * - - P P P - -
         * - - P P P - -
         */
        private static final CellType[][] board4 = {
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.DOT, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY },
        };

        /*
         * - - - - P - - - -
         * - - - P P P - - -
         * - - P P P P P - -
         * - P P P P P P P -
         * P P P P . P P P P
         * - P P P P P P P -
         * - - P P P P P - -
         * - - - P P P - - -
         * - - - - P - - - -
         */
        private static final CellType[][] board5 = {
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.DOT, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.PEG },
                        { CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.PEG, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.PEG,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.PEG, CellType.PEG,
                                        CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY },
                        { CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.PEG, CellType.EMPTY,
                                        CellType.EMPTY, CellType.EMPTY, CellType.EMPTY },
        };

        /*
         * . - - - -
         * P P - - -
         * P P P - -
         * P P P P -
         * P P P P P
         */
        private static final CellType[][] board6 = {
                        { CellType.DOT, CellType.EMPTY, CellType.EMPTY, CellType.EMPTY, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.EMPTY, CellType.EMPTY, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.EMPTY },
                        { CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG, CellType.PEG },
        };

        static final CellType[][][] boards = { board1, board2, board3, board4, board5, board6 };
}
