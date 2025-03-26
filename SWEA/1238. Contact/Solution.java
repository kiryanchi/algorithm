import java.io.*;
import java.util.*;


class S_1238 {

    static int[] vis = new int[102];
    static boolean[][] board = new boolean[102][102];
    static ArrayList<Integer>[] adj = new ArrayList[102];
    public static void main(String[] args) throws Exception {

        int TC = 10;
        for (int t = 1; t <= TC; t++) {
            sb.append('#').append(t).append(' ');

            init();
            int n = ni(), st = ni();
            for (int i = 0; i < n/2; i++) {
                int a = ni(), b = ni();
                if (board[a][b]) continue;
                adj[a].add(b);
                board[a][b] = true;
            }

            Queue<Integer> q = new ArrayDeque<>();
            
            vis[st] = 1;
            q.add(st);

            int cnt = 1;
            int lastMax = -1;
            while (!q.isEmpty()) {
                cnt++;
                lastMax = -1;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int cur = q.poll();

                    if (lastMax < cur) lastMax = cur;

                    for (int nxt : adj[cur]) {
                        if (vis[nxt] > 0) continue;

                        vis[nxt] = cnt;
                        q.add(nxt);
                    }
                }
            }

            sb.append(lastMax);

            sb.append('\n');
        }

        System.out.println(sb.toString());
    }

    static void init() {
        vis = new int[102];
        board = new boolean[102][102];
        for (int i = 0; i < 102; i++) adj[i] = new ArrayList<>();
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
