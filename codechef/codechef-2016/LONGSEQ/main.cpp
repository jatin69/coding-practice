#include <iostream>

using namespace std;

int main()
{
    string str;
    int t;
    cin>>t;
    int zeroes=0;
    int ones=0;

    while(t--)
    {
        zeroes=0;
        ones=0;
        str="";
        cin>>str;
        if(str.length()==1)
        {
            cout<<"Yes"<<endl;

        }
        else
        {
            for(int i=0; i<str.length(); i++)
            {
                if(str[i]=='0')
                {
                    zeroes++;
                }
                else
                {
                    ones++;
                }
                if(ones>1 && zeroes>1)
                {
                    cout<<"No"<<endl;
                    break;
                }
            }
            if(ones==0||zeroes==0)
            {
                cout<<"No"<<endl;

            }
            else if( (ones==1&&zeroes>=1) || (zeroes==1 && ones>=1))
            {
                cout<<"Yes"<<endl;

            }
        }
    }
    return 0;
}
