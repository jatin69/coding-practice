#include <iostream>
#include <limits.h>
#include <vector>
#include <iterator>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <stdio.h>
using namespace std;

int primes[78498];


bool test_prime(unsigned int n)
{
    if(n==2) return true;

    if (n%2	== 0) return false;

    unsigned sqrtn = sqrt((double)n);
    for (unsigned int i = 3; i <= sqrtn; i+=2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void fillprimes()
{
    int index=-1;
    for(int i=2 ; i<=1000000; ++i)
    {
        if(test_prime(i))
        {
            primes[++index]=i;
        }
    }
}

int LeastPrimeDivisor(int num)
{
    int i=-1;
    while(primes[++i]<=num)
    {
        if(num%primes[i]==0)
        {
            return primes[i];
        }
    }
    return 1;
}





int main()
{
    srand(time(NULL));
    fillprimes();

    int t;
    scanf("%d", &t);
    //cin>>t;

    while(t--)              // t test cases
    {
        int N,M;
        scanf("%d", &N);
        scanf("%d", &M);

        int A[N];

        for(int i=0; i<N; ++i)
        {
            scanf("%d", &A[i]);
        }
        int op;
        int L,R;
        for(int i=1; i<=M; i++)
        {

            scanf("%d", &op);
            scanf("%d", &L);
            scanf("%d", &R);
            L--;
            R--;    // making Human indexes to Computer indexes
            if(op==0)
            {
                for(int i=L; i<=R; ++i)
                {
                    int lpd= LeastPrimeDivisor(A[i]);
                    A[i]= A[i]/lpd;
                }
            }
            if(op==1)  //do something
            {
                int result=1;

                for(int i=L; i<=R; ++i)
                {
                    int lpd= LeastPrimeDivisor(A[i]);
                    result = max(result, lpd );

                }
                printf("%d\n" , result);
            }
        }

    }
    return 0;
}

