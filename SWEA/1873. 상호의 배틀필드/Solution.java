import java.io.*;
import java.util.*;

class Solution {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int H, W, N, dir;
    static int[] pos;
    static int[][] board;

    static void move() {
        int nx = pos[0] + dx[dir];
        int ny = pos[1] + dy[dir];

        if ((0<=nx&&nx<H) && (0<=ny&&ny<W) && (board[nx][ny] == 0)) {
            pos[0] = nx;
            pos[1] = ny;
        }
    }

    static void shoot() {
        int x = pos[0];
        int y = pos[1];

        while (0<=x&&x<H && 0<=y&&y<W) {
            if (board[x][y] > 0) {
                board[x][y]--;
                break;
            }
            x += dx[dir];
            y += dy[dir];
        }
    }

    public static void main(String[] args) throws Exception {
        int T = ni();
        for (int t = 1; t < T+1; ++t) {
            sb.append('#').append(t).append(' ');
            H = ni(); W = ni();
            init();

            for (int r = 0; r < H; r++) {
                String line = ns();
                for (int c = 0; c < W; c++) {
                    int tile = 0;
                    switch (line.charAt(c)) {
                        case '.': tile = 0; break;
                        case '*': tile = 1; break;
                        case '#': tile = 128; break;
                        case '-': tile = -1; break;
                        case '^': tile = 0; dir = 0; pos = new int[] {r,c}; break;
                        case '>': tile = 0; dir = 1; pos = new int[] {r,c}; break;
                        case 'v': tile = 0; dir = 2; pos = new int[] {r,c}; break;
                        case '<': tile = 0; dir = 3; pos = new int[] {r,c}; break;
                    }
                    board[r][c] = tile;
                }
            }

            N = ni();
            String cmds = ns();
            for (int i = 0; i < N; i++) {
                char cmd = cmds.charAt(i);
                switch (cmd) {
                    case 'S': 
                        shoot();
                        break;
                    case 'U':
                        dir = 0;
                        move();
                        break;
                    case 'R':
                        dir = 1;
                        move();
                        break;
                    case 'D':
                        dir = 2;
                        move();
                        break;
                    case 'L':
                        dir = 3;
                        move();
                        break;
                }
            }

            result();
        }

        System.out.println(sb);
    }

    static void result() {
        char tile;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i == pos[0] && j == pos[1]) {
                    if (dir == 0) tile = '^';
                    else if (dir == 1) tile = '>';
                    else if (dir == 2) tile = 'v';
                    else tile = '<';
                } else {
                    if (board[i][j] == 0) tile = '.';
                    else if (board[i][j] == 1) tile = '*';
                    else if (board[i][j] > 1) tile = '#';
                    else tile ='-';
                }

                sb.append(tile);
            }
            sb.append('\n');
        }
    }

    static void init() {
        board = new int[H][W];
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tks;

    static String ns() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return tks.nextToken();
    }

    static int ni() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return Integer.parseInt(tks.nextToken());
    }
}