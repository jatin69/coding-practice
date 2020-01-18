#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    float H,N,M;
    while(t--)
    {
        float result=0.00;
        scanf("%f %f %f",&H,&N,&M);
        while(H>N)
        {
            result++;
            H=H-(N-M);
        }
        result = result + (H/N);
        printf ("%.2f\n", result );
    }
    return 0;
}
