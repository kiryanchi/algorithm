//
// Created by 박기현 on 2024/01/28.
// 틀린 이유: 자료형을 생각하지 못 함 (long long)
//
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    stack<int> s;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        int height;
        cin >> height;

        while (!s.empty() && s.top() <= height) s.pop();
        sum += s.size();
        s.push(height);
    }

    cout << sum;
    return 0;
}