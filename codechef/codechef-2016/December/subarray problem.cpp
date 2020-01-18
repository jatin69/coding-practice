#include <iostream>

using namespace std;

bool check(int A[], int l,int h)
{
    int sum=0,pro=1;
    for(int i=l; i<=h; i++)
    {
        sum+=A[i];
        pro*=A[i];
    }
    return (sum==pro);
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int A[n+1];
        int res=0;
        for(int i=1; i<=n; i++)
        {
            cin>>A[i];
        }
        for(int sizeOfSubproblem=1; sizeOfSubproblem<=n; sizeOfSubproblem++)
        {
            // cout<<"Size of problems is : "<<sizeOfSubproblem<<endl;
            int l,h;
            int i=1;
            while(n-i+1>=sizeOfSubproblem)
            {
                //     cout<<" IN WHILE :\n";
                l=i;
                h=l+sizeOfSubproblem-1;
                //   cout<<"\nl is : "<<l<<"\t\t h is : "<<h<<endl;
                if(check(A,l,h))
                {
                    //      cout<<"\n Adding when l is : "<<l<<"\t\t h is : "<<h<<endl;
                    res++;
                }
                i++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
