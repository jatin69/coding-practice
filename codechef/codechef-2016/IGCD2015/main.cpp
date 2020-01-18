#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int main()
{
    int t,no;
    long result;
    scanf("%d",&t);
    while(t--)
    {
        result=1;
        scanf("%d",&no);
        for(int i=2; i<=no; i++)
        {
            result=result*i;
        }
        printf ("%ld\n", result);
    }
    return 0;
}
