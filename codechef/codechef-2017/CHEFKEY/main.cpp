#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,c;
        int count=0;
        scanf("%d%d%d",&n,&m,&c);

        for(int i=n; i>=1; --i)
        {
            // if exactly divisible, then proceed
            if(c%i==0)
            {
                // find quotient & check if its less than m
                int j=c/i;
                if((j<=m))
                {
                    count++;
                }
            }

        }
        printf("%d\n",count);
    }
    return 0;
}
