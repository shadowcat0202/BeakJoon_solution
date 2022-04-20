import sys
from random import random


def init_input():
    sys.stdin = open("input.txt", "r")


'''
import sys
I = sys.stdin.readline
P = sys.stdout.write

a = int(I())
A = []
P('\n', join(map(str, A)))
'''

home = [[1,4],[5,4],[3,1],[2,6],[3,3]]

for h_pos in home:
    print(h_pos[0], " ", h_pos[1])


