from audioop import reverse
import sys


def sort():
    import sys
    I = sys.stdin.readline
    P = sys.stdout.write
    
    N = int(I())
    arr = []
    for _ in range(N):
        arr.append(int(I()))

    arr.sort()
    P('\n', map(str, arr))
    
    #for i in range(len(arr)):
    #   print(arr[i])
        
def sort_2751():
    import sys
    I = sys.stdin.readline
    P = sys.stdout.write
    
    N = int(I())
    arr = []
    for _ in range(N):
        arr.append(int(I()))

    arr.sort(reverse=False)
    P('\n', map(str, arr))


def bubble_sort():
    N = int(input())
    arr = []
    for _ in range(N):
        arr.append(int(input()))

    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i] < arr[j]:
                arr[i], arr[j] = arr[j], arr[i]

    for n in arr:
        print(n)

def insertion_sort():
    N = int(input())
    arr = []
    for _ in range(N):
        arr.append(int(input()))
    
    for i in range(1, len(arr)):
        while(i > 0) & (arr[i] < arr[i - 1]):
            arr[i], arr[i -1] = arr[i-1], arr[i]
            i -= 1
    
    for i in range(len(arr)):
        print(arr[i])