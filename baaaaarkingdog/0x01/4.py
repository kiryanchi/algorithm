from util import test


def func4(n: int):
    i: int = 1

    while i <= n:
        i *= 2

    return i // 2


if __name__ == '__main__':
    assert func4(5) == 4
    assert func4(97615282) == 67108864
    assert func4(1024) == 1024

    test([func4(5), func4(97615282), func4(1024)])