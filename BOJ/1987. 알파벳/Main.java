import java.io.*;
import java.util.*;


class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int R, C, ans;
    static int[][] board;
    static boolean[] vis;

    static void dfs(int r, int c, int d) {
        vis[board[r][c]] = true;

        ans = ans < d ? d : ans;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            if (nr <= 0 || nr > R || nc <= 0 || nc > C) continue;
            if (vis[board[nr][nc]]) continue;

            dfs(nr, nc, d+1);
        }
        vis[board[r][c]] = false;
    }
    
    public static void main(String[] args) throws Exception {
        R = ni(); C = ni(); init();

        for (int r = 1; r <= R; r++) {
            String line = ns();
            for (int c = 1; c <= C; c++) {
                board[r][c] = line.charAt(c-1) - 'A';
            }
        }

        dfs(1, 1, 1);

        System.out.println(ans);
    }

    static void init() {
        board = new int[R+1][C+1];
        vis = new boolean[26];
        ans = 0;
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tks;

    static String ns() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return tks.nextToken();
    }

    static int ni() throws Exception {
        return Integer.parseInt(ns());
    }
}