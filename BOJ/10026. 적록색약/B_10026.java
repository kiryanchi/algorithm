import java.io.*;
import java.util.*;

class B_10026 {

    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, 1, 0, -1};

    static int N;
    static char[][] board;
    static boolean[][] vis;

    static Queue<int[]> q;

    static int bfs() {
        vis = new boolean[N][N];
        q = new ArrayDeque<>();

        int cnt = 0;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (vis[x][y]) continue;
                char color = board[x][y];

                q.add(new int[] {x, y});
                vis[x][y] = true;
                
                while (!q.isEmpty()) {
                    int[] item = q.poll();
                    int cx = item[0], cy = item[1];
                    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cx + dx[dir], ny = cy + dy[dir];
                        
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny]) continue;
                        if (board[nx][ny] != color) continue;
                        
                        q.add(new int[] {nx, ny});
                        vis[nx][ny] = true;
                    }
                }
                cnt++;
            }
        }

        return cnt;
    }

    public static void main(String[] args) throws Exception {
        N = ni();
        init();

        for (int x = 0; x < N; x++) {
            String line = ns();
            for (int y = 0; y < N; y++) {
                board[x][y] = line.charAt(y);
            }
        }

        sb.append(bfs()).append(' ');
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (board[x][y] == 'G') board[x][y] = 'R';
            }
        }
        sb.append(bfs());

        System.out.println(sb);

    }

    static void init() {
        board = new char[N][N];
    }


    // IO
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String ns() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int ni() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }
}