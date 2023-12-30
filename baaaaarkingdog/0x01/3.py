from util.test import test


def func3(n):
    i = 1

    while i*i < n:
        i += 1

    if i*i == n:
        return 1
    else:
        return 0


if __name__ == '__main__':
    assert func3(9) == 1
    assert func3(693953651) == 0
    assert func3(756580036) == 1

    test([func3(9), func3(693953641), func3(756580036)])