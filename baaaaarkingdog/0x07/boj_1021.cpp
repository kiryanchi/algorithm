//
// Created by 박기현 on 2024/01/22.
//
#include <bits/stdc++.h>
using namespace std;

int N, M;
deque<int> D;
int cnt = 0;

void pop() {
    if (D.empty()) return;
    D.pop_front();
}

void move_left() {
    if (D.empty()) return;
    D.push_back(D.front());
    D.pop_front();
    cnt++;
}

void move_right() {
    if (D.empty()) return;
    D.push_front(D.back());
    D.pop_back();
    cnt++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) D.push_back(i);

    while (M--) {
        int n;
        cin >> n;

        int pos = find(D.begin(), D.end(), n) - D.begin();

        while (D.front() != n) {
            if (pos <= D.size()/2) move_left();
            else move_right();
        }
        pop();
    }

    cout << cnt;

    return 0;
}
