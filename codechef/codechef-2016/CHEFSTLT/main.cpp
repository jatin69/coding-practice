#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t,min,max;
    cin>>t;
    string s1,s2;
    while(t--)
    {
        cin>>s1>>s2;
        min=0,max=0;
        unsigned int i;
        for(i=0; i<s1.length() && i<s2.length(); i++)
        {
            if(s1[i]=='?' || s2[i]=='?')
            {
                max++;
            }
            else if(s1[i]!='?' && s2[i]!='?' && s1[i]!=s2[i] )
            {
                max++;
                min++;
            }
        }
        while(i<s1.length())
        {
            max++;
            i++;
        }
        while(i<s2.length())
        {
            max++;
            i++;
        }
        cout<<min<<" "<<max<<"\n";
    }
    return 0;
}
