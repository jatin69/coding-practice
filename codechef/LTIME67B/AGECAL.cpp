/*
 * Author : Jatin Rohilla
 * Date   : 2018
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * AC - https://www.codechef.com/viewsolution/22134522
 */


#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int> A(N+1);
		
		int daysInYear = 0;
		for(int i=1;i<N+1;++i){
			cin >> A[i];
			daysInYear += A[i];
		}

		int yb, mb, db;
		cin>>yb>>mb>>db;
		
		int yc, mc, dc;
		cin>>yc>>mc>>dc;
		
		int ageInDays = 0;
		
		// different years
		if(yb!=yc){

			/*********** birthday year  ************/

			// days remaining in this month
			ageInDays += A[mb] - db + 1;
			
			// months remaining in this year
			for(int i=mb+1; i<N+1;++i){
				ageInDays += A[i];
			}
			// if leap year
			if(yb%4==0){
				ageInDays += 1;
			}


			/***********  years in between  ************/
			for(int i=yb+1 ; i<= yc-1; ++i){
				ageInDays += daysInYear;
				if(i%4==0){
					ageInDays += 1;
				}
			}
			
			/*********** current year **************/
			// months upto current date
			for(int i=1; i<mc;++i){
				ageInDays += A[i];
			}
	  		// days passed in current month
			ageInDays += dc;
		}
		// same year
		else{
			// same year, different month
			if(mc!=mb){
				
				// days remaining in birthday month
				ageInDays += A[mb] - db + 1;
					
				// months in between
				for(int i=mb+1 ; i<=mc-1; ++i){
					ageInDays += A[i];
				}

				// days passed in current month
				ageInDays += dc;
			}
			// same year, same month
			else{
				ageInDays += (dc-db+1);
			}
			
		}


		cout << ageInDays << "\n";
		
	}
    return 0;
}


