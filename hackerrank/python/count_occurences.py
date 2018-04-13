import pprint as pp
# pretty print

message = 'It was a bright cold day in April, and the clocks \
were striking thirteen.'
count = {}

for character in message:
    count.setdefault(character, 0)
    count[character] = count[character] + 1

#print(count)
    
pp.pprint(count)
# equivalent to
#print(pp.pformat(count))


allGuests = {'Alice': {'apples': 5, 'pretzels': 12},
                'Bob': {'ham sandwiches': 3, 'apples': 2},
                'Carol': {'cups': 3, 'apple pies': 1}}

#print(allGuests)
pp.pprint(allGuests)
