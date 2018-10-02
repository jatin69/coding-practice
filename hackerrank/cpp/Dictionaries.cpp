#include <iostream>
using namespace std;

int main() 
{
    long int n,k=0; 
    string Check[1000];     
  cin>>n;
  
 string A[n][2],name;
    for(long int i=0;i<n;i++)
    {
        string s,num;
       cin>>s;
       cin>>num;
        A[i][0]=s;
            if(num.length()!=8)
               cout<<"Enter 8 digit number "<<endl;
               else
            A[i][1]=num;
        }
         
   cin.ignore();
    while (getline(cin,name))
{
    if (name.empty())
        break;
        else
        {
    Check[k]=name;
       k++;
       }
  }
  
  Check[k];
  for(long int i=0;i<k;i++)
  {
          int f=0;
          string temp=Check[i];
          for(long int j=0;j<n;j++)
          {
                  if(A[j][0]==temp)
                  {
                  f=1;
                  cout<<A[j][0]<<"="<<A[j][1]<<endl;
                break;
                  }
                  }
                  if(f==1)
                 continue;
                 else
                  cout<<"Not found "<<endl;
                  }
                
            
            
            
    
    return 0;
}
