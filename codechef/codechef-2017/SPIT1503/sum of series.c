#include <iostream>
using namespace std;

int main()
{

    int t;
    cin>>t;
    int i;
    while(t--)
    {
        int A,N;
        cin>>A>>N;
        long long unsigned int fact=1;
        for(i=A ; i>1 ; i--)
        {
            fact*=i;
        }

        long long unsigned int SA=fact;
        for(i=A+1 ; i<=N; i++)
        {
            fact= fact*i;
            SA+=fact;
        }
        long long unsigned int out=  1000000007;
        long long unsigned int result = SA % out;
        cout<<result<<"\n";
    }

}
