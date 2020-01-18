#include <limits.h>
#include <stdio.h>
#include <algorithm>
int a[100005];
int main()
{
    int t,n,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        min=INT_MAX;
        min=a[0]+a[1];
        printf("%d\n",min);
    }
    return 0;
}
