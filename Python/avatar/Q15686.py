import sys
from itertools import combinations

sys.stdin = open("../input.txt", "r")


def distance(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

chicken_list = []
house_list = []

visited = [False for _ in range(13)]

for row in range(N):
    for col in range(N):
        if arr[row][col] == 1:
            house_list.append([row, col])
        elif arr[row][col] == 2:
            chicken_list.append([row, col])

minv = float('inf')
for ch in combinations(chicken_list, M):
    sumv = 0
    for home in house_list:
        sumv += min([distance(home, i) for i in ch])    #한 집에서 가장 가까운 치킨집 거리 하나 구하기
        if minv <= sumv:
            break
    if sumv < minv:
        minv = sumv
print(minv)
