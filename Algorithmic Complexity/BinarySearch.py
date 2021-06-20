def binarySearch(a, left, right, x):
    while left <= right:
        mid = (left + right) // 2
        if x == a[mid]:
             return mid
        elif x < a[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return -1


if __name__ == '__main__':
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    result = binarySearch(a, 0, n-1, x)
    print(result)
