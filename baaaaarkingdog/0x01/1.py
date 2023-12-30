from util.test import test


def func1(n: int):
    sum: int = 0

    for i in range(n + 1):
        if i % 3 == 0 or i % 5 == 0:
            sum += i

    return sum


if __name__ == '__main__':
    assert func1(16) == 60
    assert func1(34567) == 278812814
    assert func1(27639) == 178254968

    test([func1(16), func1(34567), func1(27639)])
