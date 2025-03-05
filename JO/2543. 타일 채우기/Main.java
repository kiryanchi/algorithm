import java.io.*;
import java.util.*;

class Main {

    static int N, X, Y;
    static int[][] board;

    // [x, x+n), [y, y+n) 까지 범위에 뭔가 있는지 체크
    // 뭔가: 타일 or 하수구
    // 뭔가가 있다면 참을 반환
    static boolean check(int x, int y, int d) {
        for (int i = x; i < x+d; i++) {
            for (int j = y; j < y+d; j++) {
                if (board[i][j] != 0) return true;
            }
        }
        return false;
    }

    // 뭔가 있는 곳 반대편으로 ㄱ자 타일 설치
    static void tile(int x, int y, int n, int hole) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                // 뭔가 있는 방향엔 설치 X
                if (2*i + j + 1 == hole) continue;
                if (board[x+n-1+i][y+n-1+j] == 0) board[x+n-1+i][y+n-1+j] = hole;
            }
        }
    }

    static void solve(int x, int y, int n) {
        if (n == 1) return;
        int z = n/2;

        // 뭔가 있는 방향을 찾음
        int hole = 0;
        if (check(x, y, z)) hole = 1;
        else if (check(x, y+z, z)) hole = 2;
        else if (check(x+z, y, z)) hole = 3;
        else hole = 4;

        // 반대편으로 타일을 깖
        tile(x, y, z, hole);
        
        // 그리고 재귀
        solve(x, y, z);
        solve(x, y+z, z);
        solve(x+z, y, z);
        solve(x+z, y+z, z);
    }

    public static void main(String[] args) throws Exception {
        N = ni(); X = ni(); Y = ni();
        board = new int[N][N];
        
        // 하수구 위치는 -1
        board[X][Y] = -1;
        solve(0, 0, N);

        // 하수구 위치를 0으로 변경
        board[X][Y] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) sb.append(board[i][j]).append(' ');
            sb.append('\n');
        }

        System.out.println(sb);
    }

    // IO
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int ni() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }

    static String ns() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}