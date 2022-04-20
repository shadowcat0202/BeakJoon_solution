# https://www.acmicpc.net/problem/10989
def solution():
    import sys
    I = sys.stdin.readline
    # P = sys.stdout.write

    N = int(I())
    arr = [0] * 10001
    for _ in range(N):
        arr[int(I())] += 1

    for i in range(len(arr)):
        if arr[i]:
            while arr[i] > 1000:
                print((str(i)) * 1000)
                arr[i] -= 1000
            print((str(i)) * arr[i])
