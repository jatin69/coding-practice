#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    long int a[4];
    int flag;
    while(t--)
    {
        flag=0;
        for(int i=0; i<4; ++i)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                flag=1;
            }
        }
        if(a[0]+a[1]==0)
        {
            flag=1;
        }
        else if(a[0]+a[2]==0)
        {
            flag=1;
        }
        else if(a[0]+a[3]==0)
        {
            flag=1;
        }
        else if(a[1]+a[2]==0)
        {
            flag=1;
        }
        else if(a[1]+a[3]==0)
        {
            flag=1;
        }
        else if(a[2]+a[3]==0)
        {
            flag=1;
        }

        if(flag==1)
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
