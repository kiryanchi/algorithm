import java.io.*;
import java.util.*;


class S_1868 {

    // 지뢰는 8방위로 확인한다.
    static int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    static int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};

    static int T, N;
    static char[][] board;
    static boolean[][] vis;

    static Queue<int[]> q;

    // 총 클릭 횟수 = (주변에 지뢰가 없는 타일을 클릭하는 횟수) + (주변에 지뢰가 있는 타일을 클릭하는 횟수)
    // 주변에 지뢰가 없는 타일을 먼저 클릭한 뒤, 지뢰가 있는 타일을 클릭해야 최소한으로 클릭할 수 있다.
    static int solve() {
        return bfs(true) + bfs(false);
    }

    // clear 여부로 주변에 지뢰가 없는지 있는지 확인한다.
    static int bfs(boolean clear) {
        int cnt = 0;

        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                // 해당 지역을 방문했거나 지뢰라면 스킵
                if (visitedOrIsBomb(x, y)) continue;

                // 주변에 지뢰가 없는 공간에서 클릭을 해야하는 경ㅇ
                // 주변에 지뢰가 없어야하는 경우엔 지뢰를 확인한다.
                // clear == false 라면, findBomb는 실행되지 않는다.
                // 지뢰의 개수를 세아리지 않고 주변에 지뢰가 있는지만 확인하면 된다.
                if (clear && findBomb(x, y)) continue;

                // (x, y)를 기준으로 지역 확장 시작
                q.add(new int[] {x, y});
                vis[x][y] = true;

                while (!q.isEmpty()) {
                    // 현재 위치를 가져오기 위한 poll
                    int [] item = q.poll();
                    int cx = item[0];
                    int cy = item[1];

                    // 현재 위치 주변으로 지뢰가 있다면, 맵을 확장하면 안 된다.
                    if (findBomb(cx, cy)) continue;

                    for (int dir = 0; dir < 8; dir++) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];

                        if (outOfBound(nx, ny)) continue;
                        if (visitedOrIsBomb(nx, ny)) continue;

                        q.add(new int[] {nx, ny});
                        vis[nx][ny] = true;
                    }
                }

                cnt++;
            }
        }

        return cnt;
    }

    // (x, y) 주변으로 지뢰가 있는지 확인하는 함수
    static boolean findBomb(int x, int y) {
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위를 벗어난다면 스킵
            if (outOfBound(nx, ny)) continue;
            if (board[nx][ny] == '*') return true;
        }
        return false;
    }

    // (x, y)가 [0, 0] ~ (N, N) 범위를 벗어났는지 확인하는 함수
    static boolean outOfBound(int x, int y) {
        return x < 0 || x >= N || y < 0 || y >= N;
    }

    // 해당 지역을 이미 방문했거나 지뢰인 경우 참을 반환
    static boolean visitedOrIsBomb(int i, int j) {
        return vis[i][j] || board[i][j] == '*';
    }

    public static void main(String[] args) throws Exception {
        T = ni();
        for (int t = 1; t <= T; t++) {
            N = ni();
            init();

            // N x N 배열
            for (int i = 0; i < N; i++) {
                // 입력이 공백없이 한 줄로 붙어 있어 라인을 읽어옴
                String line = ns();
                for (int j = 0; j < N; j++) {
                    // 한글자씩 board 생성
                    board[i][j] = line.charAt(j);
                }
            }

            // bfs의 결과값은 총 몇 번 클릭을 했는지가 반환됨.
            int cnt = solve();

            sb.append('#').append(t).append(' ').append(cnt).append('\n');
        }

        System.out.println(sb);
    }

    static void init() throws Exception {
        board = new char[N][N];
        vis = new boolean[N][N];
        q = new ArrayDeque<>();
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
