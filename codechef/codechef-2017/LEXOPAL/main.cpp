#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string str;
    while(t--)
    {
        str="";
        cin>>str;
        bool print=true;
        int first=0;
        int last= str.length() -1;
        while(first<=last)
        {
            if(str[first]=='.' && str[last]!='.')
            {
                str[first]=str[last];
            }
            else if(str[last]=='.' && str[first]!='.')
            {
                str[last]=str[first];
            }
            else if(str[first]=='.' && str[last]=='.')
            {
                str[first]=str[last]='a';
            }
            if(str[first]!=str[last])
            {
                cout<<"-1"<<endl;
                print=false;
                break;
            }
            first++;
            last--;
        }
        if(first==last && last=='.')
        {
            str[first]='a';
        }
        if(print==true){
        cout<<str<<endl;
        }
    }
    return 0;
}
