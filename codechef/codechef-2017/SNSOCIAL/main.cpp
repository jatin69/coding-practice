#include <iostream>

using namespace std;

void nbr_update(int **a, int**b, int i,int j,int rowmax, int colmax,int maxall)
{
    int maxi=-1;
    for(int q=i-1; q<=i+1; q++)
    {
        for(int r=j-1; r<=j+1; r++)
        {
            if( q>=0 && q<rowmax && r>=0 && r<colmax)
            {
                if(a[q][r]==maxall)
                {
                    b[i][j]=maxall;
                    return;
                }
                if(a[q][r]>maxi)
                {
                    maxi=a[q][r];
                }
            }
        }
    }
    b[i][j]=maxi;
}

bool allequal(int **b, int n, int m)
{
    int common=b[0][0];
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(b[i][j]!=common)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int **a;
    int **b;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        // initial
        a =new int*[n];
        for(int i=0; i<n; ++i)
        {
            a[i]=new int[m];
        }
        int maxall=-1;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                cin>>a[i][j];
                if(a[i][j]>maxall){
                    maxall=a[i][j];
                }
            }
        }

        int hours=0;

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(a[i][j]==maxall){

                }
            }
        }

        cout<<hours<<"\n";

    }
    return 0;
}
