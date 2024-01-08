# 0x02 기초 코드 작성 요령 2

> [바킹독의 실전 알고리즘](https://www.youtube.com/playlist?list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY) 영상을 보고 공부한 내용입니다.

## 함수 인자

### Call-By-Value

```c++
void func(int a) {
    a = 5;
}

int main(void) {
    int t = 0;
    func(t);
    cout << t; // 0
}
```
```c++
void func(int arr[]) {
    arr[0] = 10;
}

int main(void) {
    int arr[3] = {1, 2, 3};
    func(arr);
    cout << arr[0]; // 10
}
```
```c++
struct pt{
    int x, y;
};

void func(pt a) {
    a.x = 10;
}

int main(void) {
    pt tmp = {0, 0};
    func(tmp);
    cout << tmp.x; // 0
}
```

C++은 기본적으로 call-by-value 이다.
따라서 별도의 참조자나 포인터를 사용해주지 않으면 외부에서 값을 변경할 수 없다.

### 참조자 (Reference)

```c++
void swap1(int a, int b) { // X
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int* a, int* b) { // O
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap3(int& a, int& b) { // O
    int tmp = a;
    a = b;
    b = tmp;
}
```

## STL - Vector

### 기본 선언

```c++
vector<int> v(100);
v[20] = 10;
v[60] = -4;
```

### STL을 함수 인자로 넘길 때

```c++
void func1(vector<int> v) {
    v[10] = 7;
}

int main(void) {
    vector<int> v(100);
    func1(v);
    cout << v[10]; // 0
}
```

STL도 Call-By-Value로 동작한다.

```c++
bool cmp1(vector<int> v1, vector<int> v2, int idx) {
    // 동작시간 O(N)
    return v1[idx] > v2[idx];
}

bool cmp2(vector<int>& v1, vector<int>& v2, int idx) {
    // 동작시간 O(1)
    return v1[idx] > v2[idx];
}
```

## 표준 입출력

### cin/cout

```c++
int main(void) {
    string s;
    cout << "input : ";
    cin >> s;
    cout << "s is " << s;
}
/*** result ***
input : hi hello
s is hi
***************/
```

> 공백을 포함한 문자열 입력받기

```c++
string s;
getline(cin, s);
cout << s;
```

### 동기화

```c++
ios::sync_with_stdio(0);
cin.tie(0);
```

# endl 쓰지마세요.