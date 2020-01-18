#include<iostream>
#include<cmath>
using namespace std ;
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int K,N;
        double A,S=0;
        cin>>N>>K;

        for(int j=0 ; j<N ; j++)
        {
            cin>>A;
            S+=A;
            S=fmod(S,2.0);
        }

        // if sum is odd, even must be added-> result is odd-> again even added-> always even added
        if(fmod(S,2.0)!=0.0)
        {
            cout<<"even\n";
        }
        else
        {
            // if it is even-> odd must be added-> then it becomes odd and always even will be added
            if(K==1)
                cout<<"odd\n";
            else
                cout<<"even\n";
        }

    }
    return 0;
}
