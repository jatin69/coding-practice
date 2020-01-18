
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,len;
    cin>>n;

    while(n--)
    {
        cin>>len;
        char* str = new char[len];
        cin>>str;

        int noOfStrs=pow(2,(len-2));
        if(len%2==0)
            noOfStrs+=1;
            if(len==1){
                noOfStrs=1;
            }

        int j,k=0;
        char* smallest = new char[len];
        for(j=0; j+1<len; j+=2)
        {
            if(str[j] < str[j+1])
            {
                smallest[k++]=str[j];
                smallest[k++]=str[j+1];
            }
            else
            {
                smallest[k++]=str[j+1];
                smallest[k++]=str[j];
            }
        }
        if(j+1==len)
            smallest[k++]=str[len-1];

        smallest[k]='\0';
        cout<<noOfStrs<<"\n"<<smallest<<"\n";
    }
}
