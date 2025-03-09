import java.io.*;
import java.util.*;


class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    
    static int R, C;
    static int[][] board;
    static int[][] vis;

    static boolean check() {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == 1) return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        R = ni(); C = ni(); init();

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                board[r][c] = ni();
            }
        }

        int time = 0, cnt = 0;
        Queue<int[]> q = new ArrayDeque<>(), q2 = new ArrayDeque<>();
        while (check()) {
            time++;
            cnt = 0;
            vis = new int[R][C];

            q.add(new int[] {0, 0});
            vis[0][0] = 1;

            while (!q.isEmpty()) {
                int[] cur = q.poll();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur[0] + dx[dir];
                    int ny = cur[1] + dy[dir];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    if (vis[nx][ny] > 0) continue;

                        vis[nx][ny] = 1;
                    if (board[nx][ny] == 1) q2.add(new int[] {nx, ny});
                    else q.add(new int[] {nx, ny});
                }
            }

            while (!q2.isEmpty()) {
                int[] cur = q2.poll();
                
                board[cur[0]][cur[1]] = 0;
                cnt++;
            }
        }

        System.out.println(time + "\n" + cnt);
    }

    static void init() {
        board = new int[R][C];
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