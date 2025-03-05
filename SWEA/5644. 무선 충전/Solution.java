import java.io.*;
import java.util.*;

class Solution {

    static int[] dx = {0, 0, 1, 0, -1};
    static int[] dy = {0, -1, 0, 1, 0};

    static int M, A, ans;
    static int[] arr, brr;
    static int[][] position, batteries;

    static void move(int idx) {
        int dirA = arr[idx];
        position[0][0] += dx[dirA];
        position[0][1] += dy[dirA];

        int dirB = brr[idx];
        position[1][0] += dx[dirB];
        position[1][1] += dy[dirB];
    }

    static void charge() {
        ArrayList<Integer>[] list = new ArrayList[2];
        for (int i = 0; i < 2; i++) list[i] = new ArrayList<>();

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < 2; j++) {
                if (chargeable(i, j)) list[j].add(i);
            }
        }

        int max = 0, tmp = 0;
        if (list[0].size() > 0 && list[1].size() > 0) {
            for (int i : list[0]) {
                for (int j : list[1]) {
                    tmp = batteries[i][3];
                    if (i != j) tmp += batteries[j][3];
                    max = max > tmp ? max : tmp;
                }
            }
        } else if (list[0].size() > 0) {
            for (int i : list[0]) {
                max = max > batteries[i][3] ? max : batteries[i][3];
            }
        } else if (list[1].size() > 0) {
            for (int i : list[1]) {
                max = max > batteries[i][3] ? max : batteries[i][3];
            }
        }

        ans += max;
    }

    static boolean chargeable(int bIdx, int pIdx) {
        return distance(batteries[bIdx][0], batteries[bIdx][1], position[pIdx][0], position[pIdx][1]) <= batteries[bIdx][2];
    }

    static int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1-x2) + Math.abs(y1-y2);
    }

    public static void main(String[] args) throws Exception {
        int TC = ni();
        for (int t = 1; t <= TC; t++) {
            init();

            for (int i = 1; i <= M; i++) arr[i] = ni();
            for (int i = 1; i <= M; i++) brr[i] = ni();

            for (int i = 0; i < A; i++) {
                int x = ni(); int y = ni(); int c = ni(); int p = ni();
                batteries[i] = new int[] {x, y, c, p};
            }

            for (int i = 0; i <= M; i++) {
                move(i);
                charge();
            }

            sb.append('#').append(t).append(' ').append(ans).append('\n');
        }

        System.out.println(sb);
    }

    static void init() throws Exception {
        M = ni(); A = ni(); ans = 0;
        arr = new int[M+1]; brr = new int[M+1];
        position = new int[][] {{1, 1}, {10, 10}};
        batteries = new int[A][4];
    }

    static StringBuilder sb = new StringBuilder();
    static BufferedReader _br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer _st;

    static int ni() throws Exception {
        if (_st == null || !_st.hasMoreTokens()) _st = new StringTokenizer(_br.readLine());
        return Integer.parseInt(_st.nextToken());
    }
}