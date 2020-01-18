#include <iostream>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    int flag;
    int *arr=new int[cases];
    for(int i=1; i<=cases ; i++)
    {   flag=0; /// No
        char S1[10] , S2[10];
        cin>>S1;
        cin>>S2;
        int len;
        for(len=0;S1[len]!='\0';len++);
        int SS1 =len;
        for(len=0;S2[len]!='\0';len++);
        int SS2 =len;
        if((SS1==SS2) && (SS1>=1) && (SS1<=10))
        {
            arr[i]=flag;
            int j;
            for( j=0 ; j<SS1; j++)
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
                        break;
                    }
                }
            }
            if(j==SS1+1)
            flag=1; /// yes
        }
        arr[i]=flag;
    }
    for(int i=1 ; i<=cases ; i++)
    {
        if(arr[i]==1)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
}
