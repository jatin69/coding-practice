# Most upvoted
def merge_the_tools(string, k):
    '''
    approach and working -
    use K iterables at a time to extract group of K elements
    as one iterable called once contributes one element
    then zip output from each iterable to make a 'word'

    *[] unpack a list:
    Example: print(*[1,2,3,4]) = print(1,2,3,4)

    setdefault method returns the key value available in the dictionary
    and if given key is not available
    then it will provided default value and adds it to the dictionary.
    '''

    for word in zip([iter(string)]*k):
        unique = dict()
        print(''.join([ unique.setdefault(letter, letter) for letter in word if letter not in unique ]))


'''
# Even smarter
def merge_the_tools(string, k):

    for i in range(0,len(string),k):

        word=string[i:i+k]
        unique=""

        for letter in word:
            if letter not in unique:
                unique += letter
                
        print(unique)

#'''

'''
# Initial approach
def merge_the_tools(string, k):

    for i in range(0,len(string),k):

        # slice out k length word
        word=string[i:i+k]


        # list has order N search, use set , but set iterates random
        unique=[]

        # keeping unique count via set - O(1) search
        # order 1 search is not really required as only 26 characters can come. So its constant
        # but still, this is nice thing
        uniqueSet=set()
        
        for letter in word:
            if letter not in uniqueSet:
                unique.append(letter)
                uniqueSet.add(letter)
                
        print(''.join(unique))
#'''        

if __name__ == '__main__':
    string, k = "AABCAAADA",3
    merge_the_tools(string, k)
