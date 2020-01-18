#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	long long int s[100001];
	bool n[100001];
	s[0]=1;
	for(int i=1;i<=100000;i++)
	{n[i]=1;s[i]=1;}


	int p[500001]={};
	for(int i=2;i<=sqrt(100000);i++)
	{
	    int m=i*i,k=m;
	    while(m<=100000)
	    {
	        n[m]=0;
	        m+=k;

	    }
	}
	//printf("%d\n",n[4]);
	for(int i=2;i<=100000;i++)
	{

	        int m=i,k=i;
	        while(m<=100000)
	        {

	            s[m]+=i;
	            m=m+k;
	        }

	}
	for(int i=2;i<=500000;i++)
	{
	    if(p[i]==0)
	    {
	        int m=i,k=m;
	        while(m<=500000)
	        {
	            p[m]++;
	            m+=k;
	        }
	    }
	}

	for(int i=2;i<=100000;i++)
	{
	    if((p[s[i]]==2 || p[s[i]]==3 || p[s[i]]==5 || p[s[i]]==7) && n[i]==1)s[i]+=s[i-1];
	    else s[i]=s[i-1];
	}

	while(t--)
	{
	    int l,r;
	    scanf("%d%d",&l,&r);
	    long long int sum=0;
	   // for(int i=l;i<=r;i++)
	   // {
	    //    if((p[s[i]]==2 || p[s[i]]==3 || p[s[i]]==5 || p[s[i]]==7) && n[i]==1)sum+=s[i];

	    //}
	    printf("%lld\n",s[r]-s[l-1]);
	}
	return 0;
}

*/
