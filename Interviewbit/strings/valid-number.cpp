/*
 * Author : Jatin Rohilla
 * Date   : 6-5-2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 * link - https://www.interviewbit.com/problems/valid-number/
 */


#include<bits/stdc++.h>
using namespace std;

int isNumber(const string A) {

    // trim beginning and ending spaces
    // format : (spaces:ignore)(sign:option)(decimal:compulsory)
    // (dot)(number:compulsory)
    // (e)(-/+:optional)(number)

    int i = 0;
    int n = A.length()-1;

    // trim spaces
    while(i<=n && A[i]==' '){ i++; }
    while(n>=0 && A[n]==' '){ n--; }

    // optional + or - : if comes, number is compulsory
    if(i<=n && (A[i]=='+' || A[i]=='-')){
        if(i+1 <=n && (A[i+1]>='0' && A[i+1]<='9')){ i++; }
        else{ return 0; }
    }

    // decimals
    while(i<=n && A[i]>='0' && A[i]<='9'){ i++; }

	// optional dot : if comes, atleast one number is compulosry
    if(i<=n && A[i]=='.'){
        if(i+1 <=n && (A[i+1]>='0' && A[i+1]<='9')){
            i++;
            while(i<=n && A[i]>='0' && A[i]<='9'){ i++; }
        }
        else{
            return 0;
        }
    }
    
    // optional e : if comes, format is : e(+/- : optional)(digit)(digits)*
    if(i<=n && A[i]=='e'){

       if(i<=n && (A[i+1]=='+' || A[i+1]=='-')){ i++; }

       if(i+1 <=n && (A[i+1]>='0' && A[i+1]<='9')){ i++; }
       else{ return 0; }

       while(i<=n && A[i]>='0' && A[i]<='9'){ i++; }
    }

    // cout << "i is " <<i << " and n+1 is " << n+1 << " \n";
    if(i==n+1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){

	vector<string> testcases = {
		"121",
		"1e10",
		"  -1.00e10 ",
		"-01.1e-10",
		"  -.00e10",
		"  -1.",
		"- 1.00e-10 ",
		"  -1.00e10 dw"
	};
	
	for(auto s : testcases){
		cout << "For s : " << setw(20) << s << "\tresult is " << (isNumber(s) ? "YES" : "NO") << "\n";
	}

	return 0;
}

