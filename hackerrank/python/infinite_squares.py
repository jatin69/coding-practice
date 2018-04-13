'''
Applications of yeild
'''

def nextsq():
    i=0;
    while True:
        yield i,(i*i)
        i +=1

'''
Display all squares under 100
'''
limit=100

for i,num in nextsq():
    if num>limit:
        break;
    print("{0:<{widthnum}} : {1:>{widthsq}}".format(i,num,widthnum=3,widthsq=7))
