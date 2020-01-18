#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int main()
{
    int n,k,no,counter=0;
    scanf("%d %d",&n, &k);
    while(n--)
    {
        scanf("%d",&no);
        if(no%k==0)
        {
            counter++;
        }
    }
    printf ("%d\n", counter );
    return 0;
}
