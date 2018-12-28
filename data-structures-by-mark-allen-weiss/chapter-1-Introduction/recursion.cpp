/*
Four Basic rules of recursion

1. Base cases
You must always have some base cases, which can be solved without recusion.

2. Making progress towards the base case
For the cases that are to be solved recursively, the recursive call must
always be to a case that makes progress toward a base case.
If the progress is in opposite direction, the function will be non terminating.

3. Design Rule
Assume that all the recursive calls work. Let the computer do the work for you.
his rule is important because it means that when designing recursive programs, you
generally don’t need to know the details of the bookkeeping arrangements, and you don’t
have to try to trace through the myriad of recursive calls.

4. Compound Interest Rule
Never duplicate work by solving the same instance of a problem
in separate recursive calls. It is generally a bad idea to use recursion
to evaluate simple mathematical functions, such as the Fibonacci numbers. 
*/