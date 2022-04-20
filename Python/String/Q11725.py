def solution():
    str_len = int(input())
    st = str(input())
    result = 0

    for i in range(str_len):
        result += int(st[i])

    print(result)

