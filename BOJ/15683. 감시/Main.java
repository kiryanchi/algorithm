import java.io.*;
import java.util.*;


class Main {

    static int[] dx = {-1 ,0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int N, M, K, ans;

    static int[] sel;
    static int[][] board;
    static boolean[][] isWall;

    static List<int[]> cctvs;

    static boolean isPossible(int x, int y) {
        return (0<=x&&x<N && 0<=y&&y<M) && !isWall[x][y];
    }

    // (x, y)에서 dir 방향으로 쭉 감시
    static void watch(int x, int y, int dir) {
        x += dx[dir];
        y += dy[dir];

        while (isPossible(x, y)) {
            if (!(1<= board[x][y] && board[x][y] <= 6)) board[x][y] += 10;

            x += dx[dir];
            y += dy[dir];
        }
    }

    static void unwatch(int x, int y, int  dir) {
        x += dx[dir];
        y += dy[dir];

        while (isPossible(x, y)) {
            if (!(1<= board[x][y] && board[x][y] <= 6)) board[x][y] -= 10;

            x += dx[dir];
            y += dy[dir];
        }
    }

    static void solve(int cnt) {
        if (cnt == K) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (board[i][j] == 0) sum++;
                }
            }
            ans = Math.min(ans, sum);
            return;
        }

        int[] cctv = cctvs.get(cnt);
        int x = cctv[0];
        int y = cctv[1];
        int type = board[x][y];

        if (type == 1) {
            for (int dir = 0; dir < 4; dir++) {
                watch(x, y, dir);
                solve(cnt+1);
                unwatch(x, y, dir);
            }
            return;
        }
        
        if (type == 2) {
            for (int dir = 0; dir < 2; dir++) {
                watch(x, y, dir);
                watch(x, y, dir+2);
                solve(cnt+1);
                unwatch(x, y, dir);
                unwatch(x, y, dir+2);
            }
            return;
        }

        if (type == 3) {
            for (int dir = 0; dir < 4; dir++) {
                watch(x, y, dir);
                watch(x, y, (dir+1)%4);
                solve(cnt+1);
                unwatch(x, y, dir);
                unwatch(x, y, (dir+1)%4);
            }
            return;
        }

        if (type == 4) {
            for (int dir = 0; dir < 4; dir++) {
                watch(x, y, dir);
                watch(x, y, (dir+1)%4);
                watch(x, y, (dir+2)%4);
                solve(cnt+1);
                unwatch(x, y, dir);
                unwatch(x, y, (dir+1)%4);
                unwatch(x, y, (dir+2)%4);
            }
            return;
        }

        if (type == 5) {
            for (int dir = 0; dir < 4; dir++) watch(x, y, dir);
            solve(cnt+1);
            for (int dir = 0; dir < 4; dir++) unwatch(x, y, dir);
            return;
        }
    }

    public static void main(String[] args) throws Exception {
        N = ni(); M = ni(); 
        init();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = ni();
                if (board[i][j] == 6) isWall[i][j] = true;
                if (1 <= board[i][j] && board[i][j] <= 5) cctvs.add(new int[] {i, j});
            }
        }

        K = cctvs.size();
        solve(0);

        System.out.println(ans);
    }

    static void init() {
        ans = Integer.MAX_VALUE;
        board = new int[N][M];
        isWall = new boolean[N][M];
        cctvs = new ArrayList<>();
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tks;

    static int ni() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return Integer.parseInt(tks.nextToken());
    }
}