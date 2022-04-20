import sys

sys.stdin = open("../input.txt", "r")

das = 0
room_number = str(input())
number_counter = [0 for _ in range(10)]

for i in range(len(room_number)):
    number_counter[int(room_number[i])] += 1

count_sixnine = 0
for i in range(10):
    if i == 6 or i == 9:
        count_sixnine += number_counter[i]
        continue
    das = max(das, number_counter[i])

if das < count_sixnine:
    das = (count_sixnine // 2 + count_sixnine % 2)

print(das)


