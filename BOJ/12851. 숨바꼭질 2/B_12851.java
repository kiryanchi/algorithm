import java.io.*;
import java.util.*;

class B_12851 {

    static final int MAX = 100000;

    static int N, K, cnt;
    static int[] dp;      // dp[i] : time
    static Queue<Integer> q;

    static boolean check(int cur, int nxt) {
        return dp[nxt] == 0 || dp[nxt] > dp[cur];
    }

    static void bfs() {
        q.add(N);

        while (!q.isEmpty()) {
            int cur = q.poll();

            for (int nxt : new int[] {cur-1, cur+1, cur*2}) {
                if (nxt < 0 || nxt > MAX) continue;
                if (check(cur, nxt)) {
                    dp[nxt] = dp[cur]+1;
                    if (nxt == K) cnt++;
                    else q.add(nxt);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        N = ni(); K = ni(); init();

        for (int i = 0; i < N; i++) {
            dp[i] = N-i;
        }

        if (N < K) bfs();
        else cnt = 1;

        sb.append(dp[K]).append('\n').append(cnt);

        System.out.println(sb);
    }
    
    static void init() {
        cnt = 0;
        dp = new int[MAX+1];
        q = new ArrayDeque<>();
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