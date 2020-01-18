#include <stdio.h>
#include <string.h>
#include <iostream>
int setcount[26];
int n,d;
#define MAX 100009
char A[MAX],B[MAX];

void solve()
{
    scanf("%d %d", &n, &d);
    d=std::min(d,n);
    memset(setcount,0,sizeof(setcount));
    scanf("%s %s", A, B);
    int i,j;
    for(i=0; i<d; ++i)
    {
        for(j=i; j<n; j=j+d)
        {
            ++setcount[A[j]-'a'];
            --setcount[B[j]-'a'];
        }
        for(j = 0; j < 26; ++j)
        {
            if (setcount[j]!= 0)
            {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
