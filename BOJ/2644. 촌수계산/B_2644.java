import java.io.*;
import java.util.*;

class B_2644 {

    static int n, a, b, x, y, m;
    static boolean[] vis;
    static ArrayList<Integer>[] adj;

    public static void main(String[] args) throws Exception {
        n = ni(); a = ni(); b = ni(); m = ni();
        init();

        for (int i = 0; i < m; i++) {
            x = ni(); y = ni();
            adj[x].add(y);
            adj[y].add(x);
        }

        int ans = -1;
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {a, 0});
        vis[a] = true;

        while (!q.isEmpty()) {
            int[] item = q.poll();
            int cur = item[0];
            int cnt = item[1];

            if (cur == b) {
                ans = cnt;
                break;
            }

            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;

                q.offer(new int[] {nxt, cnt+1});
                vis[nxt] = true;
            }
        }

        System.out.println(ans);
    }

    static void init() {
        vis = new boolean[n+1];
        adj = new ArrayList[n+1];
        for (int i = 0; i <= n; i++) adj[i] = new ArrayList<>();
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