import java.io.*;
import java.util.*;


class Solution {

    static int N, K, highest;
    static int[][] board;
    static List<int[]> startPoints;
    
    public static void main(String[] args) throws Exception {
        int TC = ni();
        for (int tc = 1; tc <= TC; tc++) {
            init();

            sb.append('#').append(tc).append(' ').append(solve()).append('\n');
        }
        System.out.println(sb.toString());
    }

    static void init() throws Exception {
        N = ni(); K = ni();
        board = new int[N][N];
        startPoints = new ArrayList<>();
        highest = 0;

        // 입력
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                board[x][y] = ni();
                highest = Math.max(highest, board[x][y]);
            }
        }
    }
    
    static int solve() {
        int ans = 0;

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (board[x][y] == highest) {
                    // 등산로는 가장 높은 봉위리에서 시작해야한다.
                    startPoints.add(new int[] { x, y });
                }
            }
        }

        for (int k = 1; k <= K; k++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    // k만큼 봉우리를 깎은 다음
                    board[x][y] -= k;
                    ans = Math.max(ans, getMax());
                    // 다시 복구한다.
                    board[x][y] += k;
                }
            }
        }

        return ans;
    }

    // k만큼 깎인 봉우리에서 최대값을 찾음
    static int getMax() {
        int tmp = 0;
        for (int[] point : startPoints) {
            tmp = Math.max(tmp, dfs(point[0], point[1]));
        }
        return tmp;
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int dfs(int x, int y) {
        int cnt = 0;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!inBound(nx, ny) || board[nx][ny] >= board[x][y]) continue;
            cnt = Math.max(cnt, dfs(nx, ny));
        }

        return cnt + 1;
    }

    static boolean inBound(int x, int y) {
        return 0<=x&&x<N && 0<=y&&y<N;
    }

    static {
        try {System.setIn(new FileInputStream("input.txt"));}
        catch (Exception e) {}
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
