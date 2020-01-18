#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;

        long long fact=1;
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
        {
            fact*=i;
        }
        cout<<fact<<"\n";
    }
    return 0;
}
