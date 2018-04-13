# produces a list of lists for test cases
cases= [ (input().split()) for _ in range(int(input())) ]

for x,y in cases:
    try:
        print(int(x)//int(y))
    except (ZeroDivisionError,ValueError) as err :
        print("Error Code:",err)
    
        
