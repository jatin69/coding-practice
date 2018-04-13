'''
Objective : Looping multiple lists simultaneously

Keyword : yeild

yeild results one by one, and send them to caller function linearly,
rather than sending all of it together in return statement.
'''


# stops at the shortest list
def custom_zip(seq1, seq2):
    it1 = iter(seq1)
    it2 = iter(seq2)
    while True:
        yield next(it1), next(it2)


l=[1,2,3,4,5,6,7]
m=['a','b','c','d']


for i,j in custom_zip(l,m):
    print(i,j)
