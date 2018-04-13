# using regex
import re
def fun(s):

    '''
    idk why, but 0-9 is not active in my console. Works fine on regex101
    '''
    #a = re.match(r'[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z]{1,3}$',s)

    # editorial
    a = re.search(r'^[\w\d-]+@[A-Za-z0-9]+\.\w?\w?\w$',s)

    return(a)



def filter_mail(emails):
    return list(filter(fun, emails))

if __name__ == '__main__':
    emails = [ 'lara@hackerrank.com',
                'brian-23@hackerrank.com',
                'britts_54@hackerrank.com',
                'itsme@gmail',
                '@something',
                '@something.com',
                '2@something.co1',
                'sone.com'
               ]
filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(*filtered_emails,sep="\n")


'''
# Traditional

def fun(s):
    # return True if s is a valid email, else return False
    
    ext = s.find('.')
    if ext==-1:
        return False
    extension=s[ext+1:]
    if(len(extension)>3):
        return False
    
    usr = s.find('@')
    if usr==-1:
        return False
    username=s[0:usr]
    if(len(username)<1):
        return False
    for i in username:
        if not i.isalnum():
            if i!='-' and i!='_':
                return False
    
    websitename= s[usr+1:ext]
    if(len(websitename)<1):
        return False
    
    if not websitename.isalnum():
        return False
    
    return True
#'''
