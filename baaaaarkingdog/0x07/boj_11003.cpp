//
// Created by kirya on 2024-01-29.
//
#include <bits/stdc++.h>
using namespace std;

int N, L;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    deque<pair<int, int>> d;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (!d.empty() && d.front().first + L == i) {
            d.pop_front();
        }

        while (!d.empty() && d.back().second > a) d.pop_back();
        d.push_back({i, a});

        cout << d.front().second << ' ';
    }



    return 0;
}