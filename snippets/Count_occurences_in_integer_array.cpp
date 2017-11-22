/*
@author - Naveen Rohilla

Objective : Count the occurence of unique elements in array

Approach  :
1. removed duplicate elements to get a array of unique elements.
2. then compared each each unique element with original array to count occurence of that element.
3. Did the same for each unique element.
*/


#include<iostream>
using namespace std;
void removeDuplicate(int a[],int &size)
{
	for(int i=0 ; i<size ; i++)
	{
	  for(int j=i+1 ; j<size ; j++)
	  {
	    if(a[i]==a[j])
	    {
	      for(int k=j ; k<size-1 ; k++)
	      {
	        a[k]=a[k+1];
	      }
	      size--;
	      j--;
	    }
	  }
	}
}
void countOccurence(int a[],int size,int b[],int bsize,int c[])
{   int count=0;
    for(int i=0 ; i< size ; i++)
    {   count=0;
        for(int j=0 ; j<bsize ; j++)
        {
            if(a[i]==b[j])
                count++;
        }
        c[i]=count;
    }
}
int main()
{
	int a[10],b[10],c[10];
	int size=10;int bsize=10;

	for(int i=0 ; i<size ; i++)
	{
	  cout<<"Enter element "<<(i+1)<<':';
	  cin>>a[i];
	}
	for(int i=0 ; i<size ; i++)
	{
	    b[i]=a[i];
	}

	removeDuplicate(a,size);
	countOccurence(a,size,b,bsize,c);
	for(int i=0 ; i<size ; i++)
	{
	  cout<<a[i]<<"is"<<c[i]<<" times"<<endl;
	}

	return 0;
}


