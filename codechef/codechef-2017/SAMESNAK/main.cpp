#include <iostream>

using namespace std;

int main()
{ ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    long long int x11,y11;
    long long int x12,y12;
    long long int x21,y21;
    long long int x22,y22;

    while(t--)
    {
        cin>>x11>>y11>>x12>>y12;    // snake 1
        cin>>x21>>y21>>x22>>y22;    // snake 2

        // if both snakes are horizontal
        if(y11==y12 && y21==y22 )
        {
            if(y12!=y22)
            {
                // if 2 horizontal snakes are not in same row, they are not same
                cout<<"no\n";
                continue;
            }
            else if(min(x21,x22)>max(x11,x12) || max(x21,x22)<min(x11,x12))
            {
                // No intersection between snakes
                cout<<"no\n";
                continue;
            }
            else
            {
                // snakes intersect
                cout<<"yes\n";
                continue;

            }
        }

        // if both snakes are vertical
        if(x11==x12 && x21==x22 )
        {
            if(x12!=x22)
            {
                // if 2 vertical snakes are not in same column, they are not same
                cout<<"no\n";
                continue;
            }
            else if(min(y21,y22)>max(y11,y12) || max(y21,y22)<min(y11,y12))
            {
                // No intersection between snakes
                cout<<"no\n";
                continue;
            }
            else
            {
                // snakes intersect
                cout<<"yes\n";
                continue;

            }
        }


        /* one snake is horizontal and one is vertical
        cases - degree <=2 allowed

        case 1 : no touch -> no
        case 2 : absolute touch in middle of snake -> degree 3 -> no
        case 4 : pass through in middle of snake -> -> degree 4 -> no
        case 5 : pass through in start and end of snake -> -> degree 3 -> no
        case 3 : absolute touch in start and end of snake -> degree 2 -> yes
        */

        // snake 1 is horizontal and snake 2 is vertical
       /* if(y11==y12 && x21==x22)
        {
            //cool
        }
        // if snake 1 is vertical and 2 is horizontal, just swap coordinates & run same code.
        else
         */   if(y21==y22 && x11==x12)
        {
            swap(x11,x21);
            swap(y11,y21);
            swap(x12,y12);
            swap(x22,y22);
        }

        // snake 1 is horizontal and snake 2 is vertical
        // case 5
        if(min(x11,x12)==x21 || min(x11,x12)==x22 || max(x11,x12)==x21 || max(x11,x12)==x22)
        {
            cout<<"yes\n";
            continue;
        }
        cout<<"no\n";
        continue;

    }
    return 0;
}
