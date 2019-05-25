/*
 * Author : Jatin Rohilla
 * Date   : 25/01/2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * analysis - http://buttercola.blogspot.in/2014/07/leetcode-3sum-closest.html
 * sol - https://stackoverflow.com/questions/2070359/finding-three-elements-in-an-array-whose-sum-is-closest-to-a-given-number
 
 * related - http://buttercola.blogspot.in/2014/07/leetcode-4sum.html
 */

#include<iostream>
using namespace std;

int main(){

	cout<<"Hello World";

    return 0;
}

/*
int Solution::threeSumClosest(vector &A, int B) {

sort(A.begin(),A.end());

int k=0,i,j,closest,val;int diff=INT_MAX;

while(k<A.size()-2)
{
    i=k+1;
    j=A.size()-1;

    while(i<j)
    {
        val=A[i]+A[j]+A[k];
        if(val==B) return B;
        if(abs(B-val)<diff)
        {
            diff=abs(B-val);
            closest=val;
        }
        if(B>val)
        ++i;
        if(B<val)
        --j;
    }
    ++k;

}
return closest;
*/
