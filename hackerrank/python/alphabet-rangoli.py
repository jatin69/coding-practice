def print_rangoli(n):
    
    from string import ascii_lowercase as alpha
    # alpha ='abcdefghijklmnopqrstuvwxyz'

    L = []

    # from 0 to n-1
    for i in range(0,n):
        s = "-".join(alpha[n-1-i:n])
        # print(s)
        # s in reverse + ignore s[0] + s in forward
        L.append(s[::-1]+s[1:])
        # print(L)

    # width of line
    width = 2*(n-1) + 1 + 2*(n-1)

    # 0 to n-1
    for i in range(0,n):
        print(L[i].center(width, "-"))

    # ignore 0, as already printed
    for i in range(1,n):
        print(L[n-1-i].center(width, "-"))

   

if __name__ == '__main__':
    n = 3
    print_rangoli(n)
    n = 6
    print_rangoli(n)
    n = 30
    print_rangoli(n)
