#include <iostream>

using namespace std;

typedef long long int lli;

int main()
{
    int n,q;
    cin>>n>>q;
    lli a[n];
    cin>>a[0];
    lli mina=a[0],maxa=a[0],query;
    for(int i=1; i<n; ++i)
    {
        cin>>a[i];
        if(a[i]>maxa) maxa=a[i];
        if(a[i]<mina) mina=a[i];
    }
    for(int i=1; i<=q; ++i)
    {
        cin>>query;
        if(query>=mina && query<=maxa)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}
