#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    short cases;
    cin>>cases;
    for(int i=1; i<=cases ; i++)
    {
        char S1[10] , S2[10];
        cin>>S1;
        cin.ignore();
        cin>>S2;
        int SS1 =strlen(S1);
        int SS2 =strlen(S2);
        if((SS1==SS2) && (SS1>=1) && (SS1<=10))
        {
            for(int j=0 ; j<=SS1; j++)
            {
                if(S1[j]!=S2[j])
                {
                    if(S1[j]=='?')
                    {
                        S1[j]=S2[j];
                    }
                    else if(S2[j]=='?')
                    {
                        S2[j]=S1[j];
                    }
                    else
                    {
                        cout<<"No";
                        exit();
                    }
                }
            }
            cout<<"Yes";
        }
    }
}
