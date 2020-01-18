#include <iostream>
#include <stdio.h>
using namespace std;

int maxof(int** sum, int** a, int n, int i, int j)
{
    if(sum[i][j]!=-1)
    {
        return sum[i][j];
    }
    int downsum=0;
    if(i+1!=n)
    {
        int temp1=maxof(sum,a,n,i+1,j);
        sum[i+1][j]=temp1;
        int temp2=maxof(sum,a,n,i+1,j+1);
        sum[i+1][j+1]=temp2;
        downsum= (temp1>=temp2)?temp1:temp2;
    }
    return ( a[i][j] +downsum);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        //cin>>n;
        scanf("%d",&n);
        int** a = new int*[n];
        for(int i = 0; i < n; ++i)
            a[i] = new int[i+1];

        int** sum = new int*[n];
        for(int i = 0; i < n; ++i)
            sum[i] = new int[i+1];

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=i; ++j)
            {
                sum[i][j]=-1;
            }
        }

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=i; ++j)
            {
                scanf("%d",&a[i][j]);

                // cin>>a[i][j];
            }
        }
        int i=0,j=0;
        int totsum=maxof(sum,a,n,i,j);
        cout<<totsum<<"\n";
    }

    return 0;
}
