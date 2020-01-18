#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string str;
    bool head=false;
    bool tail=false;
    bool valid=true;
    int len;
    while(t--)
    {
        head=false;
        tail=false;
        valid=true;
        cin>>len;
        cin>>str;
        for(int i=0; i<len && valid; i++)
        {
            if(str[i]=='.') continue;
            if(str[i]=='H')
            {
                if(head==false)
                {
                    head=true;
                }
                else
                {
                    valid=false;
                }
            }
            else if(str[i]=='T')
            {
                if(head==true && tail==false)
                {
                    head=false;
                    tail=false;
                }
                else
                {
                    valid=false;
                }
            }
        }
        if(valid && !head && !tail)
        {
            cout<<"Valid\n";
        }
        else
        {
            cout<<"Invalid\n";
        }
    }
    return 0;
}
