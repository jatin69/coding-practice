# arbitrary
print(set('HackerRank'))

# super useful when we wanna keep its track of elements
print(set(enumerate(['H','a','c','k','e','r','r','a','n','k'])))



A= {1,2,3,5}
B= {1,2,4,6}

# symmetric difference
print(*sorted(A.difference(B).union(B.difference(A))),sep="\n")
