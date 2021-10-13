package org.codeforcause.jdsa.lecture15;

import java.util.Arrays;

public class KnightTour {
    public static void main(String[] args) {
        int[][] board = new int[8][8];
        for (int[] row : board) {
            Arrays.fill(row, -1);
        }
        int[] xMove = {2, 1, -1, -2, -2, -1, 1, 2};
        int[] yMove = {1, 2, 2, 1, -1, -2, -2, -1};
        board[0][0] = 0;
        knightTour(0,0,1,board, xMove, yMove);
    }

    public static boolean knightTour(int row, int col, int step, int[][] board, int[] xMove, int[] yMove) {
        if (step == board.length*board.length) {
            print(board);
            return true;
        }
        for (int i = 0; i < 8; i++) {
            int nextX = row + xMove[i], nextY = col + yMove[i];
            if (isSafe(nextX, nextY, board)) {
                board[nextX][nextY] = step;
                if (knightTour(nextX, nextY, step+1, board, xMove, yMove)) {
                    return true;
                } else {
                    board[nextX][nextY] = -1;
                }
            }
        }
        return false;
    }

    private static boolean isSafe(int nextX, int nextY, int[][] board) {
        return (nextX >= 0 && nextX < board.length &&   // x pos valid
                nextY >= 0 && nextY < board.length &&   // y pos valid
                board[nextX][nextY] == -1);             // unvisited pos
    }

    private static void print(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}
