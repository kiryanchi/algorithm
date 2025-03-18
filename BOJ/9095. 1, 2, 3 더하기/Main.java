import java.io.*;
import java.util.*;


class Main {

    static int T, N;
    static int[] dp = new int[12];

    public static void main(String[] args) throws Exception {
        T = ni();

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i < 12; i++) dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

        for (int t = 0; t < T; t++) {
            N = ni();
            sb.append(dp[N]).append('\n');
        }

        System.out.println(sb.toString());
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tks;

    static int ni() throws Exception {
        if (tks == null || !tks.hasMoreTokens()) tks = new StringTokenizer(br.readLine());
        return Integer.parseInt(tks.nextToken());
    }
}