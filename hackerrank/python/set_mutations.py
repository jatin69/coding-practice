'''
Problem link : https://www.hackerrank.com/challenges/py-set-mutations/problem
'''

'''
Input : 

16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 24 52
4
intersection_update 10
2 3 5 6 8 9 1 4 7 11
update 2
55 66
symmetric_difference_update 5
22 7 35 62 58
difference_update 7
11 22 35 55 58 62 66

Output :
38
#'''


# let it go waste, not needed
nA=input()

# get set A
A = set(map(int, input().split()))

# no of operations, i can be replaced with _ as not really needed
for _ in range(int(input())):
    # *args is used in variable arguments stuff
    # It will expand and take input inside it
    op, nB = input().split()
    # fetch the required attribute from Set A object
    getattr(A, op)(map(int, input().split())) 
print(sum(A))
