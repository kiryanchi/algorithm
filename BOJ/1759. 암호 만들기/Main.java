import java.io.*;
import java.util.*;


class Main {
    
    static int L, C;
    static char[] arr;
    static char[] sel;
    static boolean[] use;

    static char[] vowel = {'a', 'e', 'i', 'o', 'u'};

    static boolean isVowel(char c) {
        for (char v : vowel) {
            if (v == c) return true;
        }
        return false;
    }

    static void solve(int cnt, int idx) {
        if (cnt == L) {
            int vCnt = 0, cCnt = 0;
            for (int i = 0; i < L; i++) {
                if (isVowel(sel[i])) vCnt++;
                else cCnt++; 
            }

            if (vCnt >= 1 && cCnt >= 2) {
                for (int i = 0; i < L; i++) {
                    sb.append(sel[i]);
                }
                sb.append('\n');
            }
            return;
        }

        for (int i = idx; i < C; i++) {
            if (use[i]) continue;
            sel[cnt] = arr[i];

            use[i] = true;
            solve(cnt+1, i+1);
            use[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        L = ni(); C = ni(); init();

        for (int i = 0; i < C; i++) arr[i] = ns().charAt(0);
        Arrays.sort(arr);

        solve(0, 0);

        System.out.println(sb);
    }

    static void init() {
        arr = new char[C];
        sel = new char[L];
        use = new boolean[C];
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