//
// Created by 박기현 on 2024/01/20.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.size() << '\n'; // 3
    if (s.empty()) cout << "S is empty\n";
    else cout << "S is not empty\n";

    s.pop();
    cout << s.top() << '\n';

    s.pop();
    cout << s.top() << '\n';

    s.pop();
    if (s.empty()) cout << "S is empty\n";
    else cout << "S is not empty\n";
    return 0;
}