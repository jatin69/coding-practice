/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * TLE. Logic seems fine.
 * Logic - recursive. But pure recursion needs DFS. Used BFS here.
 */


#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){

	lli q, a,b,d;
	cin>>q;
	while(q--){
		cin>>a>>b>>d;
		queue<pair<int, int>> s;
		int steps = 0;
		int pushes = 0;
		
		s.push({d, steps});
		pushes += 1;
		
		pair<int, int> it ;

		while(!s.empty()) {
			it = s.front();
			s.pop();
//			cout << "\nReceived : "<<it.first << " at step "<<it.second;

			if(it.first==0){
				steps = it.second;
				while(!s.empty()){
					it = s.front();
					s.pop();
					if(it.second < steps){
						steps = it.second;
					}
				}
			}
			else{
				if(pushes==pow(4,steps)){
					++steps;
					pushes = 0;
				}
				s.push({it.first+a, steps});
				s.push({it.first+b, steps});
				s.push({it.first-a, steps});
				s.push({it.first-b, steps});
				pushes += 4;
			}
		}

		cout << steps << "\n";
	}
    return 0;
}

