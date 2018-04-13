"""
Example of looping multiple lists of different lengths concurrently
until all are exhausted.
"""

# library more-itertools is used
from itertools import zip_longest

import pprint as pp

l = range(10)
m = ['one', 'two', 'three']
n = ['a', 'b', 'c', 'd', 'e']


# None is mapped in place of exhausted lists
# zipping stops at end of shortest list
for ele in zip(l, m, n):
    print(ele)

# None is mapped in place of exhausted lists
# zipping stops at end of longest list
for ele in zip_longest(l, m, n):
    pp.pprint(ele)


print("\n")
for ele in zip_longest(l, m, n):
    if ele[0] is not None:
        pp.pprint(ele[0])
    if ele[1] is not None:
        pp.pprint(ele[1])
    if ele[2] is not None:
        pp.pprint(ele[2])
    print("")


print("\n")
for e1,e2,e3 in zip_longest(l, m, n):
    if e1 is not None:
        pp.pprint(e1)
    if e2 is not None:
        pp.pprint(e2)
    if e3 is not None:
        pp.pprint(e3)
    print("")
