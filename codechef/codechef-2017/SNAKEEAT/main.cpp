#include <iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,q,minlen;
    int* len =new int[100000];
    int* duplen=new int[100000];
    while(t--)
    {
        cin>>n>>q;
        for(int i=0; i<n; ++i)
        {
            cin>>len[i];
        }
        while(q--)
        {
            cin>>minlen;    // query
            for(int i=0; i<n; ++i)
            {
                duplen[i]=len[i];
            }

            // sort in descending order
            sort(duplen,duplen+n,greater<int>());

            int j,k;
            j=0;
            k=n-1;
            while(j<=k)
            {
                if(duplen[j]>=minlen)
                {
                    j++;
                }
                else if(duplen[k]<minlen)
                {
                    // snake ate a smaller snake and increased its length by 1
                    duplen[j]++;
                    k--;
                }
            }
            cout<<j<<"\n";
            //  for(int i=0;i<n;++i){cout<<duplen[i]<<"  "; }
        }

    }
    return 0;
}
