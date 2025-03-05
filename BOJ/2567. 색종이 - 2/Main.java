import java.io.*;
import java.util.*;


class Main {

    static int N, x, y;
    static boolean[][] board = new boolean[100][100];

    static void put(int x, int y) {
        for (int i = x; i < x+10; i++) {
            for (int j = y; j < y+10; j++) {
                board[i][j] = true;
            }
        }
    }

    static int count() {
        int cnt = 0;
        for (int r = 0; r < 100; r++) {
            boolean prev = false;
            for (int c = 0; c < 100; c++) {
                if (prev == false && board[r][c] == true) cnt++;
                prev = board[r][c];
            }
        }

        for (int c = 0; c < 100; c++) {
            boolean prev = false;
            for (int r = 0; r < 100; r++) {
                if (prev == false && board[r][c] == true) cnt++;
                prev = board[r][c];
            }
        }

        return cnt*2;
    }

    public static void main(String[] args) throws Exception {
        N = ni();

        for (int i = 0; i < N; i++) {
            y = ni(); x = ni();
            put(x, y);
        }

        System.out.println(count());
    }

    static BufferedReader _br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer _st;

    static int ni() throws Exception {
        if (_st == null || !_st.hasMoreTokens()) _st = new StringTokenizer(_br.readLine());
        return Integer.parseInt(_st.nextToken());
    }
}