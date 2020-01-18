#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() {
	double s,v,ans;
	int t;
    cin>>t;
    while(t--){
        cin>>s>>v;
        ans=(s*100)/v;
         printf("%.g\n", ans);
         }

	return 0;
}
