#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int th;
        cin>>th;
        int x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        int level=0;
        if(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)) <= (th*th)) /// distance 1,2
        {
            level++;
        }
        if(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)) <= (th*th)) /// distance 1,3
        {
            level++;
        }
        if(((x3-x2)*(x3-x2))+((y3-y2)*(y3-y2)) <= (th*th))
        {
            level++;    /// distance 2,3
        }

        if(level>1)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
    return 0;
}
