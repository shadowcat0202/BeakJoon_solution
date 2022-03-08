import sys


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


def main():
    from String.Q8958 import solution

    init_input()
    solution()


if __name__ == "__main__":
    main()
