package Pegame;

import java.awt.GridLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JButton;

public class BoardFrame extends JFrame {
    private int boardHeight = 9;
    private int boardWidth = 9;
    private GridLayout boardGridLayout;

    enum CellType {
        PEG,
        DOT,
        EMPTY
    }

    public BoardFrame() {
        super("Pegame");
        boardGridLayout = new GridLayout(boardHeight, boardWidth, 1, 1);
        setLayout(boardGridLayout);

        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                JButton button = new JButton();
                add(button);    
                // TODO: get type from board array and set color
                // TODO: disable empty cell buttons

                button.setActionCommand(String.format("%d %d", i, j));
                button.addActionListener(new CellButtonHandler());
            }
        }
    }

    private class CellButtonHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            JOptionPane.showMessageDialog(BoardFrame.this,
                    String.format("%s", event.getActionCommand()));
        }
    }

}
