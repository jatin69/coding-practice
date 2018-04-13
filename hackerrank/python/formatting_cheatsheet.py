'''
Source : https://pyformat.info/
'''

# single symbol multiline comment control

'''
# just alignment
print('{0:>7}'.format('zip','hello'))
print('{1:<7}'.format('zip','hello'))
print('{1:^7}'.format('zip','hello'))

# text is left align by default
print('{0:10}'.format("hello"))
# numbers are right align
print('{0:10f}'.format(3.141592653589793))


# with padding
print('{0:*>7}'.format('zip'))
print('{0:*<7}'.format('zip'))
print('{0:*^7}'.format('zip'))
#'''

'''
# Truncating
print('{0:.5}'.format('xylophone'))

# decimal places
print('{0:.5f}'.format(4.2))
print('{0:.5f}'.format(4.2453142352))

# Truncating and padding
# {<positional-argument>:<padding><alignment><width>.<truncating> }
print('{0:*^12.5}'.format('xylophone')) 
# whole string limit
print('{0:*^12.5}'.format(1234.567))
# decimal places 
print('{0:*^12.5f}'.format(1234.567))
#'''

'''
# Numbers
# text is left align by default
print('{0:10}'.format("hello"))
# numbers are right align
print('{0:10f}'.format(3.141592653589793))

# Just 'f' is left align, as no limit found
print('{0:f}'.format(3.141592653589793))
print('{0:.10f}'.format(3.141592653589793))


# padding numbers
# auto padded with space
print('{:4d}'.format(42))
# padding with zero
print('{:04d}'.format(42))
print('{:010d}'.format(42))

# padding with numbers and float
print('{:06.2f}'.format(3.141592653589793))

#'''
'''
Just perfect-
For integer values providing a precision doesn't make much sense
and is actually forbidden in the new style (it will result in a ValueError).
'''

'''
# signed numbers
print('{:+d}'.format((- 23)))
print('{:+d}'.format((23)))

# New style formatting is also able to control the position of the sign
# symbol relative to the padding.

# digit will come in width 5
print('{:=+5d}'.format(-23))
print('{:=+5d}'.format(23))
#'''


'''
# name placeholders
print('{first} {last}'.format(first='Hodor', last='Hodor!'))

# with data
data = {'first': 'Hodor', 'last': 'Hodor!'}
print('{first} {last}'.format(**data))



# Getitem and Getattr
person = {'first': 'Jean-Luc', 'last': 'Picard'}
print('{p[first]} {p[last]}'.format(p=person))

data = [4, 8, 15, 16, 23, 42]
print('{d[4]} {d[5]}'.format(d=data))

# even with class- super cool
class Plant(object):
    type = 'tree'
    kinds = [{'name': 'oak'}, {'name': 'maple'}]

print('{p.type}'.format(p=Plant()))
print('{p.type}: {p.kinds[0][name]}'.format(p=Plant()))

#'''

'''
# THE NEXT BIG THING

# Parametrized formats


# Parametrized alignment and width:
print('{:{align}{width}}'.format('test', align='^', width='10'))

#Parametrized precision:
print('{:.{prec}} = {:.{prec}f}'.format('Gibberish', 2.7182, prec=3))
print('{1:.{prec}} = {1:.{prec}f}'.format('Gibberish', 2.7182, prec=3))


# width and precision
print('{:{width}.{prec}f}'.format(2.7182, width=5, prec=2))
# notice the minor change
print('{:{prec}} = {:{prec}}'.format('Gibberish', 2.7182, prec='.3'))

# with numbers - positional arguments
print('{:{}{}{}.{}}'.format(2.7182818284, '>', '+', 10, 3))

# mixed with keyword arguments
print('{:{}{sign}{}.{}}'.format(2.7182818284, '>', 10, 3, sign='+'))

#'''


'''
from datetime import datetime
print('{:%Y-%m-%d %H:%M}'.format(datetime(2001, 2, 3, 4, 5)))

# parameterized date and time
dt = datetime(2001, 2, 3, 4, 5)
print('{:{dfmt} {tfmt}}'.format(dt, dfmt='%Y-%m-%d', tfmt='%H:%M'))
#'''


#'''
# The date time works because of __format__() method
# For custom objects - INSANELY AWESOME

class MYCLASS(object):

    def __format__(self, format):
        if (format == 'open-the-pod-bay-doors'):
            return "I'm afraid I can't do that."
        else:
            return 'Invalid format'

print('{:open-the-pod-bay-doors}'.format(MYCLASS()))
print('{:some-invalid-format}'.format(MYCLASS()))



















