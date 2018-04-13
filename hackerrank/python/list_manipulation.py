a=[1,2,3]
print(a)
# [1, 2, 3]

b=a*3
print(b)
# [1, 2, 3, 1, 2, 3, 1, 2, 3]

c=[a]*3
print(c)
# [[1, 2, 3], [1, 2, 3], [1, 2, 3]]

d=zip(*[a]*3)
print(*d)
# (1, 1, 1) (2, 2, 2) (3, 3, 3)


# You can do it in-place like so:
# a[:] = [ i*5 for i in a]
e = [ i*5 for i in a]
print(e)
# [5, 10, 15]
