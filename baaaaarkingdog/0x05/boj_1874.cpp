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

    int idx = 1;
    string answer = "";
    while (N--) {
        int n;
        cin >> n;

        while (idx <= n) {
            S.push(idx++);
            answer += "+\n";
        }

        if (n == S.top()) {
            answer += "-\n";
            S.pop();
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << answer;
    return 0;
}