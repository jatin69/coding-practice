#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int s1=0,s2=0,s11=0,s22=0,w,l=0;
    while(t--)
    {
        cin>>s11>>s22;
        s1+=s11;
        s2+=s22;
        if(abs(s1-s2)>=l)
        {
            l=abs(s1-s2);
            w=s1>s2?1:2;
        }
    }
    cout<<w<<" "<<l;
    return 0;
}
