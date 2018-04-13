'''
test case

1 2 3 4 5 6 7 8 9 10 11 12 23 45 84 78
2
1 2 3 4 5
100 11 12


1 2 3
2
1 2
1 3
'''

A = set(input().split())
n = int(input())
Bs = [ set(input().split()) for _ in range(n) ]

L=True
for B in Bs:
    if B-A != set() or A==B:
        L=False    
        break

print(L)
