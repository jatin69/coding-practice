#include <iostream>

using namespace std;

void nbr_update(int **a, int**b, int i,int j,int rowmax, int colmax,int maxall){
    int maxi=-1;

    for(int q=i-1; q<=i+1; q++){
        for(int r=j-1; r<=j+1; r++){
            if( q>=0 && q<rowmax && r>=0 && r<colmax){
               //     cout<<"\nchecking ele : a["<<q<<"]["<<r<<"]";
                    if(a[q][r]==maxall){
                        b[i][j]=maxall;
                        return;
                    }

                    if(a[q][r]>maxi){
                    maxi=a[q][r];
                }
            }
        }
    }
    b[i][j]=maxi;
    /*
    cout<<"\nmaxi is :"<<maxi;
    for(int q=i-1; q<=i+1; q++){
        for(int r=j-1; r<=j+1; r++){
            if( q>=0 && q<rowmax && r>=0 && r<colmax){
                if(b[q][r]<maxi){
               cout<<"\nstoring "<<maxi<<" at: b["<<q<<"]["<<r<<"]";
                b[q][r]=maxi;
                }
            }
        }
    }
    */
}

bool allequal(int **b, int n, int m){
    int common=b[0][0];
    for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(b[i][j]!=common){
                    return false;
                }
            }
        }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int **a;
    int **b;
    bool done;
    int n,m,maxall,hours,turn;
    while(t--)
    {
        cin>>n>>m;
        a =new int*[n];
        for(int i=0; i<n; ++i){
            a[i]=new int[m];
        }
        b =new int*[n];
        for(int i=0; i<n; ++i){
            b[i]=new int[m];
        }

        maxall=-1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>a[i][j];
                b[i][j]=a[i][j];
                if(a[i][j]>maxall){
                    maxall=a[i][j];
                }
            }
        }
        done=false;
        hours=0;
        turn=0;
        done=allequal(a,n,m);

        while(!done){
                // cout<<"ds";
            ++hours;
    if(turn%2==0){


       /*      cout<<"\n\n A initial now matrix is :\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            cout<<a[i][j];
            }
            cout<<"\n";
        }
        */
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
             //   if(true || a[i][j]!=maxall){
                    nbr_update(a,b,i,j,n,m,maxall);
               // }
            }
        }
        done=allequal(b,n,m);

      /*   cout<<"\n\n A transformed to B - after now matrix is :\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            cout<<b[i][j];
            }
            cout<<"\n";
        }
        */
    }
    else{
     /*        cout<<"\n\n B initial now matrix is :\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            cout<<b[i][j];
            }
            cout<<"\n";
        }
        */
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
              //  if( true || b[i][j]!=maxall){
                    nbr_update(b,a,i,j,n,m,maxall);
                //}
            }
        }
        done=allequal(a,n,m);

       /*  cout<<"\n\n B-> transformed to A  after now matrix is :\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            cout<<a[i][j];
            }
            cout<<"\n";
        }
        */
    }         //           cout<<"\n\n passing index i="<<i<<" , j="<<j<<"\n";
        turn++;

        }
        cout<<hours<<"\n";

    }
    return 0;
}
