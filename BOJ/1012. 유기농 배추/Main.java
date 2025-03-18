import java.io.*;
import java.util.*;


class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int T, M, N, K;
    static boolean[][] board, vis;

    static void dfs(int x, int y) {
        vis[x][y] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!inBound(nx, ny)) continue;
            if (board[nx][ny] && !vis[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }

    static boolean inBound(int x, int y) {
        return 0<=x&&x<N && 0<=y&&y<M;
    }

    public static void main(String[] args) throws Exception {
        T = ni();

        for (int t = 0; t < T; t++) {
            M = ni(); N = ni(); K = ni();
            init();

            for (int i = 0; i < K; i++) {
                int x = ni(), y = ni();
                board[y][x] = true;
            }

            int cnt = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (board[i][j] && !vis[i][j]) {
                        cnt++;
                        dfs(i, j);
                    }
                }
            }

            sb.append(cnt).append('\n');
        }

        System.out.println(sb.toString());
    }

    static void init() {
        board = new boolean[N][M];
        vis = new boolean[N][M];
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tks;

    static int ni() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return Integer.parseInt(tks.nextToken());
    }
}