#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; ++i)
    {
        cin>>str[i];
    }
    string currpass;
    for(int i=0; i<n; ++i)
    {
        currpass=str[i];
        std::reverse(currpass.begin(),currpass.end());
        for(int j=i; j<n; ++j)
        {
            if(currpass.compare(str[j])==0)
            {
                cout<<currpass[(currpass.length()/2)+1];
                break;
            }
        }
    }
    return 0;
}
