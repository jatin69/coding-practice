def print_formatted(number):
    res=""
    width = len("{0:b}".format(number))
    for i in range(1,n+1):
        print("{0:{width}d} {0:{width}o} {0:{width}X} {0:{width}b}".format(i, width=width))


n=16
print_formatted(n)
