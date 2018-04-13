from collections import Counter, OrderedDict

'''
Inherit basic functionalities from Counter
Then override a specific function with OrderedDict
Super Cool
'''
class OrderedCounter(Counter, OrderedDict):
    pass

s = "aaabbccee"
[print(*c) for c in OrderedCounter(sorted(s)).most_common(3)]

'''
# Note: In Counter.most_common(). 
# Elements with equal counts are ordered arbitrarily.
'''


'''
approach -
A class OrderedCounter which inherits Counter, OrderedDict


The difference between a ordinary counter and Ordered Counter is
in its roots.

Counter
 |  Method resolution order:
 |      Counter
 |      __builtin__.dict
 |      __builtin__.object

OrderedCounter
 |  Method resolution order:
 |      OrderedCounter
 |      collections.Counter
 |      collections.OrderedDict
 |      __builtin__.dict
 |      __builtin__.object

'''
