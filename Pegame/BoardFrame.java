package Pegame;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.BorderFactory;
import javax.swing.JButton;

public class BoardFrame extends JFrame {
    PegSolitaireGame pGame;
    private GridLayout boardGridLayout;
    protected JButton[][] buttons;
    protected int[] cellSelection; // selected cell

    public BoardFrame(PegSolitaireGame game) {
        super("Pegame");
        pGame = game;
        boardGridLayout = new GridLayout(pGame.board.length, pGame.board[0].length, 8, 8);
        buttons = new JButton[pGame.board.length][pGame.board[0].length];
        setLayout(boardGridLayout);

        for (int i = 0; i < pGame.board.length; i++) {
            for (int j = 0; j < pGame.board[i].length; j++) {
                buttons[i][j] = new JButton();
                JButton button = buttons[i][j];

                button.setSize(3, 5);

                switch (pGame.board[i][j]) {
                    case PEG:
                        button.setBackground(Color.BLUE);
                        button.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 8));
                        button.addActionListener(new PegButtonHandler());
                        break;
                    case DOT:
                        button.setBackground(Color.GRAY);
                        button.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 8));
                        button.addActionListener(new DotButtonHandler());
                        break;
                    case EMPTY:
                        button.setEnabled(false);
                        break;
                }

                add(button);
                button.setActionCommand(String.format("%d,%d", i, j));
            }
        }
    }

    public BoardFrame() {
        this(new PegSolitaireGame());
    }

    private int[] parseActionCommand(ActionEvent event) {
        int[] command = new int[2];
        String[] temp = event.getActionCommand().split(",");
        command[0] = Integer.parseInt(temp[0]);
        command[1] = Integer.parseInt(temp[1]);
        return command;
    }

    private class PegButtonHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            if (cellSelection != null) {
                buttons[cellSelection[0]][cellSelection[1]]
                        .setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 8));
            }

            cellSelection = parseActionCommand(event);
            buttons[cellSelection[0]][cellSelection[1]].setBorder(BorderFactory.createLineBorder(Color.GREEN, 8));

            // JOptionPane.showMessageDialog(BoardFrame.this,
            // String.format("(%d,%d)", cellSelection[0], cellSelection[1]));
        }
    }

    private class DotButtonHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            // TODO: move
            int[] dotLocation = parseActionCommand(event);
            boolean success = false;
            if (dotLocation[0] == cellSelection[0] && dotLocation[1] < cellSelection[1]) {
                success = pGame.moveLeft(cellSelection[0], cellSelection[1], buttons);
            } else if (dotLocation[0] == cellSelection[0] && dotLocation[1] > cellSelection[1]) {
                success = pGame.moveRight(cellSelection[0], cellSelection[1], buttons);
            } else if (dotLocation[1] == cellSelection[1] && dotLocation[0] < cellSelection[0]) {
                success = pGame.moveUp(cellSelection[0], cellSelection[1], buttons);
            } else if (dotLocation[1] == cellSelection[1] && dotLocation[0] > cellSelection[0]) {
                success = pGame.moveDown(cellSelection[0], cellSelection[1], buttons);
            }

            if (!success)
                JOptionPane.showMessageDialog(BoardFrame.this,
                        String.format("Invalid move! (%d,%d) to (%d,%d)", cellSelection[0], cellSelection[1], dotLocation[0], dotLocation[1]));

            repaint();
            revalidate();
        }
    }

}
