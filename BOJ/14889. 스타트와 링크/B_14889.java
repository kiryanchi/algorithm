import java.io.*;
import java.util.*;


class B_14889 {

    static int N, min;
    static int[][] S;

    static int[] sel;
    static boolean[] use;

    static void solve(int cnt, int idx) {
        if (cnt == N/2) {
            // 스타트 팀 합, 링크 팀 합
            int sSum = 0, lSum = 0;
            for (int i = 0; i < N-1; i++) {
                for (int j = i+1; j < N; j++) {
                    // 같은 팀이 아니라면 continue
                    if (use[i] != use[j]) continue;
                    if (use[i]) {
                        sSum += S[i][j] + S[j][i];
                    } else {
                        lSum += S[i][j] + S[j][i];
                    }
                }
            }
            min = Math.min(min, Math.abs(sSum-lSum));
            return;
        }

        for (int i = idx; i < N; i++) {
            if (use[i]) continue;
            use[i] = true;
            solve(cnt+1, i+1);
            use[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        N = ni();
        init();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                S[i][j] = ni();
            }
        }

        solve(0, 0);

        System.out.println(min);
    }

    static void init() {
        min = Integer.MAX_VALUE;
        S = new int[N][N];
        use = new boolean[N];
        sel = new int[N];
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