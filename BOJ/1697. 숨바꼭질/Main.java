import java.io.*;
import java.util.*;

class Main {

    static final int MAX = 100000;

    static int N, K;
    static int[] vis;

    static boolean check(int cur, int nxt) {
        return vis[nxt] == 0 || vis[nxt] > vis[cur];
    }

    public static void main(String[] args) throws Exception {
        N = ni(); K = ni();
        init();

        Queue<Integer> q = new ArrayDeque<>();
        q.add(N);
        vis[N] = 0;

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == K) {
                break;
            }

            for (int nxt : new int[] {cur+1, cur-1, cur*2}) {
                if (nxt < 0 || nxt >= MAX+1) continue;
                if (check(cur, nxt)) {
                    q.add(nxt);
                    vis[nxt] = vis[cur]+1;
                }
            }
        }

        System.out.println(vis[K]);
    }

    static void init() {
        vis = new int[MAX+1];
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