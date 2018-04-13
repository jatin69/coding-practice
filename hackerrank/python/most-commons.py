#!/bin/python3
# this means use python 3

'''
test case :
aabbbccde

output:
b 3
a 2
c 2

Sort output in descending order of occurrence count. 
If the occurrence count is the same, sort the characters in ascending order.

'''

if __name__ == "__main__":

    #s = input().strip()

    s = "aabbbccde"

    from collections import Counter

    # If order of letters is not important
    # d = sorted(Counter(s).items(), key=lambda value: value[1], reverse=True)[:3]

    # If order of letters needs to be preserved.
    d = sorted(Counter(s).items(), key= lambda x: (-x[1],x[0]))[:3]

    # print("\n".join(x[0]+" "+str(x[1]) for x in d))

    # using unpacking
    [ print(*x) for x in d ]


'''
Approach :

Counter(s)
Standard counter from collections

.items()
iterates over key, value pair

lambda x: (-x[1],x[0])
sort descending using x[1] i.e. value
sort  ascending using x[0] i.e. key
'''
