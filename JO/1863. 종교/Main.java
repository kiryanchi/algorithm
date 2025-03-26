import java.io.*;
import java.util.*;


class Main {

    static int n, m;
    static int[] p;

    static int find(int x) {
        if (p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    static void union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;
        if (p[u] == p[v]) p[u]--;
        if (p[v] < p[u]) p[u] = v;
        else p[v] = u;
    }

    public static void main(String[] args) throws Exception {
        n = ni(); m = ni(); init();
        
        while (m-- > 0) {
            int a = ni(), b = ni();

            union(a, b);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i] < 0) ans++;
        }

        System.out.println(ans);
    }

    static void init() {
        p = new int[n+1];
        for (int i = 0; i <= n; i++) p[i] = -1;
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
