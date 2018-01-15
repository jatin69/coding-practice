/*
explanation ref - https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean
usage ref - https://www.geeksforgeeks.org/g-fact-93/
logic - 
The compiler is allowed to make one implicit conversion to resolve the parameters to a function. 
What this means is that the compiler can use constructors callable with a single parameter 
to convert from one type to another in order to get the right type for a parameter.

benefit - 
The reason you might want to do this is to avoid accidental construction that can hide bugs. Contrived example:
You have a MyString(int size) class with a constructor that constructs a string of the given size. 
You have a function print(const MyString&), and you call print(3) (when you actually intended to call print("3")). 
You expect it to print "3", but it prints an empty string of length 3 instead.



*/