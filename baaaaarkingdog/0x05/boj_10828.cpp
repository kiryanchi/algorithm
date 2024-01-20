//
// Created by 박기현 on 2024/01/20.
//
#include <bits/stdc++.h>
using namespace std;

int N;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--) {
        string op;
        cin >> op;

        if (op == "push") {
            int n;
            cin >> n;

            S.push(n);
        } else if (op == "top") {
            if (S.empty()) cout << "-1\n";
            else cout << S.top() << '\n';
        } else if (op == "size") {
            cout << S.size() << '\n';
        } else if (op == "pop") {
            if (S.empty()) cout << "-1\n";
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if (op == "empty") {
            if (S.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}