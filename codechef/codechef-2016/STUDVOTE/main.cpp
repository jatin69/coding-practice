#include <iostream>

using namespace std;

int main()
{
    int t,n,k,count;
    cin>>t;
    while(t--)
    {
        count=0;

        cin>>n>>k;

        int a[n];
        int votes[n];
         for(int i=0; i<n; ++i)
        {
            a[i]=0;
            votes[i]=0;
        }


        for(int i=0; i<n; ++i)
        {
            cin>>a[i];
            a[i]--;                 // to manage index 0
            if(i==a[i])
            {
                votes[a[i]]= -110;   // if he votes for himself, he will never win
            }
            votes[a[i]]++;
        }

        for(int i=0; i<n; ++i)
        {
            if(votes[i]>=k)
            {
                count++;
            }
        }
        cout<<count<<"\n";


    }
    return 0;
}
