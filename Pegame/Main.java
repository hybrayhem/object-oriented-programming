package Pegame;

import javax.swing.JButton;

import java.awt.Color;
import java.awt.Container;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.GridLayout;

public class Main {

    public static void main(String args[]) {
        BoardFrame boardFrame = new BoardFrame();
        boardFrame.setBackground(Color.BLACK);
        boardFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        boardFrame.setSize(600, 600); // set frame size
        boardFrame.setVisible(true); // display frame
    } // end main
}
