def solution():
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    sum = arr[0]
    for i in range(1, len(arr)):
        arr[i] = arr[i] + arr[i-1]
        sum += arr[i]
    print(sum)

