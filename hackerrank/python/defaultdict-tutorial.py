from collections import defaultdict

# take input
n,m=[int(i) for i in input().split()]

# create a default dic that holds list in values
a = defaultdict(list)

# take list a input, append indexes to unique input keys
for i in range(n):
    a[input()].append(i+1)

# pass the input of B as key,
# if already in a, will return its list, then unpack it using *
# else -1 needs to be displayed
for j in range(m):
    print(*a.setdefault(input(), [-1]))
    


'''
Input -

5 3
a
a
b
a
b
a
b
c

output-
1 2 4
3 5
-1
'''
