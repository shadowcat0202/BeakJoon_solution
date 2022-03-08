def solution():
    N = int(input())

    for _ in range(N):
        result = 0
        st = str(input())
        cnt = 0
        for i in range(len(st)):
            if st[i] == "O":
                cnt += 1
                result += cnt
            else:
                cnt = 0
        print(result)