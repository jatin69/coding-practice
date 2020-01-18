#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter no of bits :  ";
    cin>>num;

    cout<<"\n";
    int total_combinations= pow(2,num);
    int div;
    for(int i=0; i<total_combinations; ++i)
    {
        /* used in C -
        printf("%d%d%d%d\n", i/8%2, i/4%2, i/2%2, i%2);
        */
        for(int j=num-1; j>=0; --j)
        {
            /*  basic c++
             div=pow(2,j);
            cout<<(i/div)%2; */

            /*This works because an easier way to divide by 2 is by Right shift */
            cout<<(i>>j)%2;

        }
        cout<<"\n";

    }
    return 0;
}
