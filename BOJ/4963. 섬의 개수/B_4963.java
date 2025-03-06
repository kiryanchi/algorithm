import java.io.*;
import java.util.*;

class B_4963 {

    static int[] dx = {-1, -1, -1, 0, 1, 1, 1, 0};
    static int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};

    static int w, h;
    static int[][] map;
    static boolean[][] vis;

    public static void main(String[] args) throws Exception {
        while (true) {
            w = ni(); h = ni();
            if (w == 0 && h == 0) break;

            map = new int[h][w]; vis = new boolean[h][w];

            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    map[x][y] = ni();
                }
            }

            int ans = 0;
            Queue<int[]> q = new ArrayDeque<>();
            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (vis[x][y] || map[x][y] == 0) continue;
                    ans++;

                    q.offer(new int[] {x, y});
                    vis[x][y] = true;

                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        int cx = cur[0];
                        int cy = cur[1];

                        for (int dir = 0; dir < 8; dir++) {
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];

                            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                            if (vis[nx][ny] || map[nx][ny] == 0) continue;

                            q.offer(new int[] {nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                }
            }

            sb.append(ans).append('\n');
        }
        System.out.println(sb);
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