import java.io.*;
import java.util.*;

class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int N, M;
    static int[][] board;

    public static void main(String[] args) throws Exception {
        N = ni(); M = ni();
        board = new int[N+2][M+2];

        for (int x = 1; x <= N; x++) {
            String line = ns();
            for (int y = 1; y <= M; y++) {
                board[x][y] = line.charAt(y-1)-'0';
            }
        }

        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[] {1, 1});

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];

            if (cx == N && cy == M) break;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if (board[nx][ny] != 1) continue;

                q.add(new int[] {nx, ny});
                board[nx][ny] = board[cx][cy] + 1;
            }
            
            board[cx][cy] = 0;
        }

        System.out.println(board[N][M]);
    }

    // IO
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static long nl() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Long.parseLong(st.nextToken());
    }

    static int ni() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }

    static String ns() throws Exception {
        if (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}