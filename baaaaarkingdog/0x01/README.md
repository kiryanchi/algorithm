# 0x01 기초 코드 작성 요령 1

> [바킹독의 실전 알고리즘](https://www.youtube.com/playlist?list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY) 영상을 보고 공부한 내용입니다.
> 
> 본 영상은 C++로 작성되어있으나, 본인의 편의하에 파이썬으로 변환하여 문제를 풀이하고 있습니다.

## [1번 문제](./1.py)

N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환하는 함수 func1(int N)을 작성하라. N은 10만 이하의 자연수이다.

- func1(16) = 60
- func1(34567) = 278812814
- func1(27639) = 178254968

## [2번 문제](./2.py)

주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
arr의 각 수는 0 이상 100 이하이고 N은 1000 이하이다.

- func2({1, 52, 48}, 3) = 1
- func2({50, 42}, 2) = 0
- func2({4, 13, 63, 87}, 4) = 1

## [3번 문제](./3.py)

N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성하라. N은 10억 이하의 자연수이다.

- func3(9) = 1
- func3(693953651) = 0
- func3(756580036) = 1

## [4번 문제](./4.py)

N 이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라. N은 10억 이하의 자연수이다.

- func4(5) = 4
- func4(97615282) = 67108864
- func4(1024) = 1024