s = input()

for method in [str.isalnum, str.isalpha, str.isdigit, str.islower, str.isupper]:
    print(any(method(c) for c in s))

'''
t = type(s)
for method in [t.isalnum, t.isalpha, t.isdigit, t.islower, t.isupper]:
    print(any(method(c) for c in s))
#'''


'''
#My approach

if __name__ == '__main__':
    s = input()
    a,b,c,d,e=[False]*5
    for ch in s:
        if a is False:
            a=ch.isalnum()
        if b is False:
            b=ch.isalpha()
        if c is False:
            c=ch.isdigit()
        if d is False:
            d=ch.islower()
        if e is False:
            e=ch.isupper()
    
    print(a)
    print(b)
    print(c)
    print(d)
    print(e)

#'''
