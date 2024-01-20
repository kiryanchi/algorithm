//
// Created by 박기현 on 2024/01/20.
//
#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int, int>> towers;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    towers.push({0, 100000001});
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;

        while (towers.top().second < height) towers.pop();

        cout << towers.top().first << ' ';

        towers.push({i, height});
    }
    return 0;
}