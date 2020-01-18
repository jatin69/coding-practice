#include <iostream>
#include <stdio.h>
using namespace std;

struct factor
{
    int powtwo;
    int powfive;
};

int main()
{
    int t,n,m,type,L,R,sum,temp,powfive,powtwo,power,tom;
    long long X,Y;
    long long a[100000];
    factor ob[100000];
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&a[i]);
            powfive=0;
            powtwo=0;
            temp=a[i];
            while(temp>0 && temp%2==0)
            {
                powtwo++;
                temp=temp/2;
            }
            while(temp>0 && temp%5==0)
            {
                powfive++;
                temp/=5;
            }
            ob[i].powfive=powfive;
            ob[i].powtwo=powtwo;
        }
        for(int i=1; i<=m; ++i)
        {
            cin>>type;
            switch(type)
            {
            case 1:
            {
                scanf("%d%d%d",&L,&R,&X);
                powfive=0;
                powtwo=0;
                temp=X;
                while(temp>0 && temp%2==0)
                {
                    powtwo++;
                    temp=temp/2;
                }
                while(temp>0 && temp%5==0)
                {
                    powfive++;
                    temp/=5;
                }
                for(int i=L-1; i<R; ++i)
                {
                    ob[i].powfive+=powfive;
                    ob[i].powtwo+=powtwo;
                }
            }
            break;

            case 2:
            {
                scanf("%d%d%d",&L,&R,&Y);
                powfive=0;
                powtwo=0;
                temp=Y;
                while(temp>0 && temp%2==0)
                {
                    powtwo++;
                    temp=temp/2;
                }
                while(temp>0 && temp%5==0)
                {
                    powfive++;
                    temp/=5;
                }
                factor Y;
                Y.powfive=powfive;
                Y.powtwo=powtwo;
                for(int i=L-1; i<R; ++i)
                {
                    powfive=0;powtwo=0;
                    temp=(i-(L-1)+1);
                    while(temp>0 && temp%2==0)
                    {
                        powtwo++;
                        temp=temp/2;
                    }
                    while(temp>0 && temp%5==0)
                    {
                        powfive++;
                        temp/=5;
                    }
                    ob[i].powfive=Y.powfive+powfive;
                    ob[i].powtwo=Y.powtwo+powtwo;
                }
            }
            break;

            case 3:
            {
                scanf("%d%d",&L,&R);
                powtwo=0;
                powfive=0;
                for(int i=L-1; i<R; ++i)
                {
                    powtwo+=ob[i].powtwo;
                    powfive+=ob[i].powfive;
                }
                if(powfive<=powtwo)
                {
                    power=powfive;
                }
                else
                {
                    power=powtwo;
                }
                sum+=power;
            }
            break;
            }

        }
        printf("%d\n",sum);
    }
    return 0;
}
