//
// Created by 박기현 on 2024/01/28.
//
#include <bits/stdc++.h>
using namespace std;

int N;
int answer[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    stack<pair<int, int>> s;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        while (!s.empty() && s.top().second < n) {
            answer[s.top().first] = n;
            s.pop();
        }
        s.push({i, n});
    }

    while (!s.empty()) {
        answer[s.top().first] = -1;
        s.pop();
    }

    for (int i = 1; i <= N; i++)
        cout << answer[i] << ' ';
    return 0;
}