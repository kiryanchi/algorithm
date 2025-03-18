import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] p;
    static ArrayList<int[]> edges;

    static int find(int x) {
        if (p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    static boolean union(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;
        if (p[u] == p[v]) p[u]--;
        if (p[v] < p[u]) p[u] = v;
        else p[v] = u;

        return true;
    }
    
    public static void main(String[] args) throws Exception {
        N = ni(); init();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int c = ni();
                if (i == j) continue;
                edges.add(new int[] {c, i, j});
            }
        }

        Collections.sort(edges, (e1, e2) -> Integer.compare(e1[0], e2[0]));

        long cnt = 0, sum = 0;
        for (int[] edge : edges) {
            if (union(edge[1], edge[2])) {
                cnt++;
                sum += edge[0];
            }
            if (cnt == N-1) break;
        }

        System.out.println(sum);
    }

    static void init() {
        p = new int[N+1];
        for (int i = 0; i <= N; i++) p[i] = -1;
        edges = new ArrayList<>();
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
