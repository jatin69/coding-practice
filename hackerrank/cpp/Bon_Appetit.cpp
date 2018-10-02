#include<iostream>
#include<vector>
#include <cstdlib>
using namespace std;

void bonAppetit(vector<int> bill, int k,int b)
{
     int n=bill.size(),sum=0;
     int not_ordered=bill[k];
     cout<<not_ordered<<endl;
     for(int i=0;i<n;i++)
     {
             if(bill[i]!=not_ordered)
             sum+=bill[i];
             }
             cout<<sum<<endl;
             long anna_part=sum/2;
              
             if(anna_part==b)
             cout<<"Bon Appetit "<<endl;
             else
                 cout<<abs(b-anna_part)<<endl;
                 
 }
 int main()
 {
     int n,k,b;
     cout<<"Enter number of items ordered : ";
     cin>>n;
    vector<int> A(n);
     cout<<"Enter price of items ordered :"<<endl;
     for(int i=0;i<n;i++)
     cin>>A[i];
     cout<<"Enter index of item Anna doesn't eat  ";
     cin>>k;
     cout<<"Enter amount of money that Anna contributed to the bill  ";
     cin>>b;
     bonAppetit(A,k,b);
     system("pause");
     return 0;
     }
