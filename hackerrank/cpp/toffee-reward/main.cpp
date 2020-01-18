#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    while(1)
    {
        int t;
        cin>>t;
        if(t==-1)
        {
            break;
        }
        int arr[t];
        int ele;
        int sum=0;
        for(int i=0; i<t; ++i)
        {
            cin>>ele;
            sum+=ele;
            arr[i]=ele;
        }
        /// sum is odd & packets are even
        if(sum%2!=0 && t%2==0)
        {
            cout<<"-1\n";
            continue;
        }
        // sort it
        sort(arr,arr+t);
        int count=0;
        int min=0;
        for(int i=t-1; i>=0; i--)
        {
            min=arr[0];
            for(int j=0; j<=i-1; j++)
            {
                if(arr[j]>min)
                {
                    arr[j]++;
                    arr[i]--;
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
