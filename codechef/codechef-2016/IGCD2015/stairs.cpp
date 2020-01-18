#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

int main()
{
    int t;
    scanf("%d",&t);
    int N,H,X,I,L,S;
    int lift_time;
    int inf_time;
    while(t--)
    {
        scanf("%d %d %d %d",&N,&H,&X,&I);
        scanf("%d %d",&L,&S);
        inf_time= abs(I-H)*S;
        lift_time= abs(H-X)*L + abs(I-H)*L;
        if(inf_time < lift_time)
        {
            printf ("%s\n", "STAIRS");
        }
        else
        {
            printf ("%s\n", "LIFT");

        }
    }
    return 0;
}
