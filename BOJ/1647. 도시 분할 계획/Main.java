import java.io.*;
import java.util.*;

public class Main {

    static class Edge implements Comparable<Edge> {
        int a, b, c;

        Edge (int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(c, o.c);
        }
    }
    
    static int N, M, A, B, C;
    static int[] p;
    static ArrayList<Edge> edges;

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
        N = ni(); M = ni(); init();

        while (M-- > 0) {
            A = ni(); B = ni(); C = ni();
            edges.add(new Edge(A, B ,C));
        }

        Collections.sort(edges);

        int cnt = 0;
        long ans = 0;
        for (Edge edge : edges) {
            if (union(edge.a, edge.b)) {
                cnt++;
                ans += edge.c;
            }
            if (cnt == N - 1) {
                ans -= edge.c;
                break;
            }
        }

        System.out.print(ans);
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
