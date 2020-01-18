#include <iostream>
#include <math.h>
using namespace std;
int mypow(int base, int exponent) {
    int n = 1;
    for (int i = 0; i < exponent; i++) {
        n *= base;
    }
    return n;
}


int main()
{int a,b;
    cin>>a>>b;
    int digit=0;
    int sum=0;
    int result=a-b;
    int power=-1;
    while(result>0){
        sum+=digit* mypow(10,power);
        power++;
        digit=result%10;
        result=result/10;
    }
    if(digit==9){
        digit=digit-1;
    }
    else{
        digit++;
    }
    sum+= digit* pow(10,power);
    cout<<sum;

    return 0;
}
