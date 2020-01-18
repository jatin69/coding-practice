#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*
A BETTER APPROACH IS HASHING -
maintain count of elements & display them

#include <stdio.h>
int main()
{
	int i, j, k, l, m, n, t, a[1000007]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		a[j]++;
	}
	k=n;
	for(i=1;i<=n&&k!=0;i++)
	{
		for(j=0;j<a[i];j++)
		{
			printf("%d\n",i);
			k--;
		}
	}
	return 0;
}
*/

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; ++i)
        scanf("%d",&a[i]);

    sort(a,a+n);

    for(int i=0; i<n; ++i)
        printf("%d\n",a[i]);

    return 0;
}





/*

// #include <iostream>
// using namespace std;
#include <stdio.h>
int main()
{
    int t,tempindex,temp;
    //cin>>t;     // total elements required
    scanf("%d",&t);
    int tot=t;  // for display
    int a[t];   // array for holding elements

   // cin>>a[0];	// take first element as it is
    scanf("%d",&a[0]);
    int n=1;	// size of curr array
    t--;        // inputs_remaining--;

    while(t--)
    {
       // cin>>a[n];	    // take input at last
        scanf("%d",&a[0]);
        n++;		    // size increased by 1
        temp=a[n-1];    // hold in temp
        tempindex=n-2;  // comparison index'

        while(temp < a[tempindex] && tempindex>=0)
        {
            a[tempindex+1]=a[tempindex];
            tempindex--;
        }
        a[tempindex+1]=temp;
    }
    // display loop
    int i=0;
    for(i=0; i<tot; ++i)
    {
        printf("%d\n",a[i]);
        //cout<<a[i]<<"\n";
    }
    return 0;
}

*/
