#include <iostream>

using namespace std;

bool check(int* a , int n )
{
    for(int i=1; i<n; ++i)
        if(a[a[i-1]-1]!=i) return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    do
    {
        if(n==0) break;
        int *a=new int[n];
        for(int i=0; i<n; ++i)    cin>>a[i];
        if(check(a,n))
        {
            cout<<"ambiguous\n";
        }
        else
        {
            cout<<"not ambiguous\n";
        }
    }
    while(cin>>n);
    return 0;
}
