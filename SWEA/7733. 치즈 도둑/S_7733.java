import java.io.*;
import java.util.*;


class S_7733 {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int T, N, ans, max;
    static int[][] board;
    static boolean[][] vis;

    static Queue<int[]> q;

    static int bfs(int limit) {
        vis = new boolean[N][N];
        q = new ArrayDeque<>();
        
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check(i, j, limit)) continue;

                cnt++;
                q.add(new int[] {i, j});
                vis[i][j] = true;
                
                while (!q.isEmpty()) {
                    int[] item = q.poll();
                    int cx = item[0], cy = item[1];

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir], ny = cy + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (check(nx, ny, limit)) continue;

                        q.add(new int[] {nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                
            }
        }

        return cnt;
    }

    static boolean check(int x, int y, int limit) {
        return vis[x][y] || board[x][y] <= limit;
    }

    public static void main(String[] args) throws Exception {
        T = ni();
        for (int t = 1; t <= T; t++) {
            N = ni();
            init();

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    board[i][j] = ni();
                    max = Math.max(max, board[i][j]);
                }
            }

            for (int k = 0; k <= max; k++) {
                ans = Math.max(ans, bfs(k));
            }

            sb.append('#').append(t).append(' ').append(ans).append('\n');
        }

        System.out.println(sb);
    }

    static void init() {
        board = new int[N][N];
        ans = 0;
        max = 0;
    }

    // IO
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int ni() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }
}