import java.io.*;
import java.util.*;

public class Solution {

    static int T, N, S;
    static int[][] board;

    static void up() {
        for (int c = 0; c < N; c++) {
            int r = 0, nr = 0;
            while (r < N) {
                for (nr = r+1; nr < N; nr++) {
                    if (board[nr][c] != 0) break;
                }
                // 끝까지 없으면 다음 열
                if (nr == N) break;
    
                if (board[r][c] == 0) {
                    board[r][c] = board[nr][c];
                    board[nr][c] = 0;
                } else {
                    if (board[r][c] == board[nr][c]) {
                        board[r][c] *= 2;
                        board[nr][c] = 0;
                    }
                    r++;
                }
            }
        }
    }

    static void left() {
        for (int r = 0; r < N; ++r) {
            int c = 0, nc = 0;
            while (c < N) {
                for (nc = c+1; nc < N; nc++) {
                    if (board[r][nc] != 0) break;
                }
                if (nc == N) break;

                if (board[r][c] == 0) {
                    board[r][c] = board[r][nc];
                    board[r][nc] = 0;
                } else {
                    if (board[r][c] == board[r][nc]) {
                        board[r][c] *= 2;
                        board[r][nc] = 0;
                    }
                    c++;
                }
            }
        }
    }

    static void down() {
        for (int c = N-1; c >= 0; --c) {
            int r = N-1, nr = N-1;
            while (r >= 0) {
                for (nr = r-1; nr >= 0; nr--) {
                    if (board[nr][c] != 0) break;
                }
                if (nr < 0) break;

                if (board[r][c] == 0) {
                    board[r][c] = board[nr][c];
                    board[nr][c] = 0;
                } else {
                    if (board[r][c] == board[nr][c]) {
                        board[r][c] *= 2;
                        board[nr][c] = 0;
                    }
                    r--;
                }
            }
        }
    }

    
    static void right() {
        for (int r = N-1; r >= 0; --r) {
            int c = N-1, nc = N-1;
            while (c >= 0) {
                for (nc = c-1; nc >= 0; nc--) {
                    if (board[r][nc] != 0) break;
                }
                if (nc < 0) break;

                if (board[r][c] == 0) {
                    board[r][c] = board[r][nc];
                    board[r][nc] = 0;
                } else {
                    if (board[r][c] == board[r][nc]) {
                        board[r][c] *= 2;
                        board[r][nc] = 0;
                    }
                    c--;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        T = Integer.parseInt(br.readLine());
        for (int t = 1; t < T+1; ++t) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken()); S = st.nextToken().charAt(0);
            
            init();
            
            for (int r = 0; r < N; r++) {
                st = new StringTokenizer(br.readLine());
                for (int c = 0; c < N; c++) board[r][c] = Integer.parseInt(st.nextToken());
            }

            if (S == 'u') up();
            else if (S == 'd') down();
            else if (S == 'l') left();
            else if (S == 'r') right();

            print(sb, t);
        }
        
        System.out.println(sb);
    }

    static void print(StringBuilder sb, int t) {
        sb.append('#').append(t).append(' ').append('\n');
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) sb.append(board[r][c]).append(' ');
            sb.append('\n');
        }
    }

    static void init() {
        board = new int[N][N];
    }
}
