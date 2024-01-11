# 0x04 연결 리스트

> [바킹독의 실전 알고리즘](https://www.youtube.com/playlist?list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY) 영상을 보고 공부한 내용입니다.

## 정의와 성질

|   | 배열 | 연결 리스트 |
|---|----|--------|
|k번째 원소의 접근| O(1) | O(k)   |
|임의 위치에 원소 추가/제거| O(N) | O(1)   |
|메모리 상의 배치| 연속 | 불연속 |
|추가적으로 필요한 공간 (Overhead) | | O(N) |

## STL List

```c++
int main(void) {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); // auto t = L.begin();
    
    L.push_front(10); // 10 1 2
    cout << *t << '\n'; // t가 가리키는 값을 출력 = 1
    
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6);
    t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
    t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                    // 10 6 1 5, t가 가리키는 값은 5
    
    // for over C++11
    cout << *t << '\n';
    for(auto i : L) cout << i << ' ';
    
    // for below C++11
    cout << '\n';
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << ' ';
}
```

## [BOJ 1406: 에디터](./boj_1406.cpp)