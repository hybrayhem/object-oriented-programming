package Pegame;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.GridLayout;

public class Main {

    public static void main(String args[]) {

        JFrame mainFrame = new JFrame("Pegame");

        int boardHeight = 9;
        int boardWidth = 9;
        // JPanel boardPanel = new JPanel(new GridLayout(boardHeight, boardWidth, 1,
        // 1));
        JPanel boardPanel = new JPanel();
        GridLayout boardGridLayout = new GridLayout(boardHeight, boardWidth, 1, 1);
        boardPanel.setLayout(boardGridLayout);

        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                JButton button = new JButton(i + " " + j);
                boardPanel.add(button);
                // boardPanel.add(new JButton(i + " " + j));
            }
        }
        mainFrame.getContentPane().add(boardPanel);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setSize(800, 800); // set frame size
        mainFrame.setVisible(true); // display frame
    } // end main
}
