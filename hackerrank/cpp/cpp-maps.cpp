/*
 * Author : Jatin Rohilla
 * Date   : 5/12/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */
 /*
test case
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {

    map<string,int> m;
    map<string,int>::iterator it;
    int type,q,marks;
    cin>>q;
    string name;
    while(q--){
        cin>>type;
        cin>>name;

        switch(type){
            case 1:{
                cin>>marks;
                it=m.find(name);
                if(it==m.end()){
                    m.insert(make_pair(name,marks));
                }
                else{
                    m[name]= m[name] + marks;
                }
            }break;
            case 2:{
                m.erase(name);
            }break;
             case 3:{
                 it=m.find(name);
                 if(it==m.end()){
                     cout<<"0"<<"\n";
                 }
                 else{
                     cout<<m[name]<<"\n";
                 }
            }break;
        }
    }
    return 0;
}

/*
Following code
int main() {
    map<string, int> m;
    cout << "Map size: " << m.size() << endl;
    cout << "Missing key value: " << m["test"] << endl;
    cout << "Map size: " << m.size() << endl;

    return 0;
}

generates next output

Map size: 0
Missing key value: 0
Map size: 1

So as you see performing an operator[] on our map
resulted in a side effect of creating map element <key>, <default value>.

It kinda doesn't matter for original problem, since you can solve it as was shown above.
But this could be notable for some particular cases elsewhere.
*/

