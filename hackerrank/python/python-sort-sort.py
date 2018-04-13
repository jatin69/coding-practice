import sys


def main():
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    arr = []
    for arr_i in range(n):
       arr_t = [int(arr_temp) for arr_temp in input().strip().split(' ')]
       arr.append(arr_t)
    k = int(input().strip())
    sort(arr,key=arr[0][k])
    print(arr)
    
if __name__ == "__main__":
    main()
    
