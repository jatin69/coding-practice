def count_substring(string, sub_string):

    index=0
    count=0
    while(1):
        found=string.find(sub_string,index)
        #print(found)
        if(found!=-1):
            count = count+1
            index=found+1
        else:
            break
        
    return count


if __name__ == '__main__':
    string = "ABCDCDC"
    sub_string = "CDC"
    
    count = count_substring(string, sub_string)
    print(count)
