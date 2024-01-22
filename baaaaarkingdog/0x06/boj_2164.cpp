//
// Created by 박기현 on 2024/01/22.
//
#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> Q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) Q.push(i);

    bool discard = true;
    while (Q.size() > 1) {
        if (!discard) Q.push(Q.front());
        Q.pop();
        discard = !discard;
    }

    cout << Q.front();

    return 0;
}