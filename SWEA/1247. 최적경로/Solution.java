import java.io.*;
import java.util.*;

class Solution {

    static int TC, N, ans;
    static int[] xrr, yrr;
    static int[] sel;
    static boolean[] use;

    static StringBuilder sb = new StringBuilder();

    static int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1- x2) + Math.abs(y1 - y2);
    }

    static void solve(int idx, int prev, int sum) {
        if (idx == N+1) {
            sum += distance(xrr[prev], yrr[prev], xrr[N+1], yrr[N+1]);
            ans = Math.min(ans, sum);
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (use[i]) continue;
            int dist = distance(xrr[prev], yrr[prev], xrr[i], yrr[i]);
            sel[idx] = i;

            use[i] = true;
            if (sum + dist <= ans)
            solve(idx+1, i, sum + dist);
            use[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        TC = ni();
        for (int t = 1; t <= TC; ++t) {
            N = ni();
            init();

            // 회사 좌표
            xrr[0] = ni(); yrr[0] = ni();

            // 집 좌표
            xrr[N+1] = ni(); yrr[N+1] = ni();
            
            // 고객 좌표
            for (int i = 1; i <= N; i++) {
                xrr[i] = ni(); yrr[i] = ni();
            }

            // 순열
            solve(1, 0, 0);

            sb.append('#').append(t).append(' ').append(ans).append('\n');
        }

        System.out.println(sb);
    }

    static void init() {
        ans = Integer.MAX_VALUE;
        sel = new int[N+2]; use = new boolean[N+2];
        xrr = new int[N+2]; yrr = new int[N+2];
    }

    static BufferedReader _br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer _st;

    static int ni() throws Exception {
        if (_st == null || !_st.hasMoreTokens()) _st = new StringTokenizer(_br.readLine());
        return Integer.parseInt(_st.nextToken());
    }
}