/*
 * Author : Jatin Rohilla
 * Date   : 5-11-2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Accepted.
 https://www.codechef.com/NOV18B/problems/HMAPPY1
 */


#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;

#define debugON 0

int main(){

	int n, q, k;
	cin>>n>>q>>k;

	vector<int> A(n);
	for(int i=0; i<n; ++i){
		cin>> A[i];
	}

	string s;
	cin >> s;

	int shift = 0;
	int res = 0;
	bool moved = true;
	
	// only check for possible solutions
	vector<piii> possibleSolutions;
	
	// find first max and second max island
	
	int firstMAX = INT_MIN, secondMAX = INT_MIN;
	int firstMAX_i, firstMAX_j, secondMAX_i, secondMAX_j;
	int count = 0;
	int i;
	bool allOne = false;
	bool allZero = false;
	
	for( i = 0;i<n; ++i){
		if(A[i]==0){
			count++;
		}
	}
	if(count == n){
		allZero = true;
	}
	
	count = 0;
	for( i = 0;i<n; ++i){
		
		if(A[i]==1){
			count++;
		}
		else{
			
//			cout << "\ncoming inside ";
//			cout << "\ncount is : " << count;
			
			// if it's highest => make it highest & make firstMax as second highest
			if(count >= firstMAX){
				
				secondMAX = firstMAX;
				secondMAX_j = firstMAX_j;
				secondMAX_i = firstMAX_i;
				
				firstMAX = count;
				firstMAX_j = i-1;
				firstMAX_i = firstMAX_j - count + 1;
				
			}
			else if(count >= secondMAX){

				secondMAX = count;
				secondMAX_j = i-1;
				secondMAX_i = secondMAX_j - count + 1;

			}
			
			count = 0;
		}
	}
	
//	cout << "\ncoming inside ";
//	cout << "\ncount is : " << count;

	// if it's highest => make it highest & make firstMax as second highest
	if(count >= firstMAX){

		secondMAX = firstMAX;
		secondMAX_j = firstMAX_j;
		secondMAX_i = firstMAX_i;

		firstMAX = count;
		firstMAX_j = i-1;
		firstMAX_i = firstMAX_j - count + 1;
		
		if(count == n){
			allOne = true;
		}
	}
	else if(count >= secondMAX){

		secondMAX = count;
		secondMAX_j = i-1;
		secondMAX_i = secondMAX_j - count + 1;

	}

	count = 0;

	
	// only 2 are enough, because boundaries can cut only one at once
	possibleSolutions.push_back( make_pair(firstMAX, make_pair(firstMAX_i, firstMAX_j)));
	
	if(secondMAX != INT_MIN){
	 	possibleSolutions.push_back( make_pair(secondMAX, make_pair(secondMAX_i, secondMAX_j)));
	}
	
	
	// find corners if important
	
	// start corner
	int corner_i, corner_j;
	bool isCornerRequired  = true;
	int ii;
	int cornerCount = 0;
	if(isCornerRequired){
		// start corner
		for(ii=0;ii<n;++ii){
			if(A[ii]!=1){
				if(ii==0){
					isCornerRequired = false;
					break;
				}
				else{
//					corner_i = 0;
					corner_j = ii - 1;
//					cout << "\ncorner j is " << corner_j << " XXXXXXXXXXXXXXXXXX \n ";
					cornerCount += corner_j - 0 + 1;
				}
				break;
			}
		}
		if(ii==n-1){
			isCornerRequired = false;
		}
	}

	if(isCornerRequired){
		// end corner
		
		for(ii=n-1;ii>=0;--ii){
			if(A[ii]!=1){
				if(ii==n-1){
					isCornerRequired = false;
					break;
				}
				else{
					corner_i = ii+1;
	//				corner_j = n-1;
					cornerCount += n-1 - corner_i + 1;
				}
				break;
			}
		}
		if(ii == 0){
			isCornerRequired = false;
		}
	}
	
	if(isCornerRequired){
		possibleSolutions.push_back( make_pair(cornerCount, make_pair(corner_i, corner_j)));
	}
	
	
	sort(possibleSolutions.begin(), possibleSolutions.end(), [](piii a, piii b) { return a.second.first < b.second.first ; });
	
	
	
	for(auto i : s){

		// right shift
		if(i=='!'){
			shift++;
			moved = true;
		}
		// query
		else{
			if(moved){
				// shift & query
				
				if(allOne){
					res = min(n, k) ;
				}
				else if(allZero){
					res = 0;
				}
				else{

					int currCount = 0;
					int maxCount = INT_MIN;

					for( auto x : possibleSolutions){

						if(debugON){
							cout << "\nValues are :\n" << "i : " << x.second.first << " and j : " << x.second.second << "\n";
						}
						

						int xx = ( x.second.first + (shift%n) + n)%n ;
						int yy = ( x.second.second + (shift%n) + n)%n ;
						
						if(debugON){
							cout << "\n and they become : " << " i :" << xx << " and j : " << yy << "\n";
						}
						
						if( xx >= 0 && yy <= n-1 && xx <= yy ){
							currCount = x.first;
							if(debugON){
								cout << "curr count is " << currCount << "\n";
							}
							maxCount = max(currCount, maxCount);
						}
						else{
							currCount = max(( yy - 0 + 1), (n-1 - xx + 1));
							if(debugON){
								cout << "curr count is " << currCount << "\n";
							}
							maxCount = max(currCount, maxCount);
						}
					}

					res = min(maxCount, k);
				}
				
			}

			if(debugON){
				cout << "\n\nres is : ";
			}
			

			cout << res << "\n";
			moved = false;
		}

	}


    return 0;
}

/*

16 100 20
1 1 1 1 0 0 1 1 1 1 0 0 1 1 1 1
?!!?!?!?!?!?!!?!?!?!?!?!?!!???!?!?


todo -
reduce from n^2

>> 3 pieces

middle => long can break and becomes less

first + last => less can add and become one+++++++++++++665

// done

reduced to order N

*/

