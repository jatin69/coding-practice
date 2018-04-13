# my approach
'''
if __name__ == '__main__':
    n = int(input())
    #arr = map(int, input().split())
    
    arr = [ int(x) for x in input().split() ]
    arr.sort(reverse=True)
    
    i=0
    while arr[i] == arr[i+1]:
        i=i+1
    
    print(arr[i+1])
    
'''

# elegant and short
'''
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
	print(sorted(list(set(arr)))[-2])
'''


# without set and sort
'''
i = int(input())
lis = list(map(int,raw_input().strip().split()))
z = max(lis)
while max(lis) == z:
    lis.remove(max(lis))

print max(lis)
'''

