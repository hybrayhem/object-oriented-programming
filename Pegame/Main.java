package Pegame;

import javax.swing.JButton;
import java.awt.Container;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.GridLayout;

public class Main {

    public static void main(String args[]) {
        BoardFrame boardFrame = new BoardFrame();
        boardFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        boardFrame.setSize(800, 800); // set frame size
        boardFrame.setVisible(true); // display frame
    } // end main
}
