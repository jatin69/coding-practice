# split(' ') preserves multiple spaces

def capitalize(string):
    return ' '.join([word.capitalize() for word in string.split(' ')])

'''
# changes need to be done in same list
# as indefinite number of spaces
def capitalize(string):
    words=string.split()
    res=[]
    for word in words:
        capital = word[0].upper()
        if(len(word)>1):
             capital += word[1:]
        res += [capital]
    return ' '.join(res)
'''

if __name__ == '__main__':
    string = "1 s 2 3g"
    capitalized_string = capitalize(string)
    print(capitalized_string)
