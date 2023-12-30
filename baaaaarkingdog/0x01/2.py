from util.test import test

def func2(arr, n):
    ptr1, ptr2 = 0, n-1

    while ptr1 <= ptr2:
        if arr[ptr1] + arr[ptr2] == 100:
            return 1
        elif arr[ptr1] + arr[ptr2] > 100:
            ptr2 -= 1
        else:
            ptr1 += 1

    return 0


if __name__ == '__main__':
    assert func2([1, 52, 48], 3) == 1
    assert func2([50, 42], 2) == 0
    assert func2([4, 13, 63, 87], 4) == 1

    test([func2([1, 52, 48], 3), func2([50, 42], 2), func2([4, 13, 63, 87], 4)])
