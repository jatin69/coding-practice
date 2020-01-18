#include <stdio.h>

int main()
{
    int t,n,x,digits,carry;
    // array to store factorial
    char fact[20000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        fact[0]=1;
        digits=1;
        carry=0;

        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<digits; ++j)
            {
                x=fact[j]*i+carry;
                fact[j]=x%10;
                carry=x/10;
            }
            while(carry>0)
            {
                fact[digits]=carry%10;
                carry/=10;
                digits++;
            }

        }
        //for printing
        for(int i=digits-1; i>=0; i--)
        {
            printf("%d",fact[i]);
        }
        printf("\n");



    }
    return 0;
}
