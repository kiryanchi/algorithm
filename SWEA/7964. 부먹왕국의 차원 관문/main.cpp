#include <iostream>
using namespace std;

int T, N, D, cnt, ans;
vector<bool> city;

void init() {
    cnt = ans = 0;
    city.clear();
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> D;
        init();
        // 1번도시부터 들어옴
        for (int i = 0; i < N; i++) {
            bool x; cin >> x;
            city.push_back(x);
        }
        city.push_back(1);

        for (int i = 0; i <= N; i++) {
            if (city[i] == 0) cnt++;
            else {
                ans += (cnt / D);
                cnt = 0;
            }
        }

        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}