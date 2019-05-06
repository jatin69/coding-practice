/*
 * Author : Jatin Rohilla
 * Date   : 26/11/2017
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 * Problem link : https://www.interviewbit.com/problems/reverse-the-string/
 */


#include<iostream>
using namespace std;

#include<string>

// leveraging string
void reverseWords(string &A) {
    string res="";
    for(int i=0;i<A.length();++i){
		string word="";
        while(i<A.length() && A[i]==' '){ i++; }

		while(i<A.length() && A[i]!=' '){
            word.push_back(A[i]);
            i++;
        }
        i--;
        
        // for first time
        if(res==""){
        	res=word;
		}
		else if(word!=""){
			// changing from " " to "-" for easy view
			res = word+"-"+res;
		}
        
    }
    A = res;
}

// manually handling a lot of cases
void reverseWords_new_session(string &A) {

    string res;

    // compaction of spaces
    for(int i=0; i<A.length(); ++i){

        // keep other chars as it is
        while(i<A.length() && A[i]!=' '){ res += A[i]; i++; }

        // compact all spaces to one
        while(i<A.length() && A[i]==' '){ i++; }
		// changing from " " to "-" for easy view
		res += ' ';

        i--;
    }
	
	// remove spaces from starting and end
    int k;
    for(k=0; k<res.length() && res[k]==' '; ++k);
    int ws = k;
    for(k=res.length()-1; k>=0 && res[k]==' '; --k);
	int len = k-ws+1;
    A = res.substr(ws, len);

	// in-place reversal of each word
    for(int i=0; i<A.length(); ++i){

        // make a word
        int ws = i;
        while(i<A.length() && A[i]!=' '){ i++; }
        int we = i-1;

        // reverse the word
        int p = ws;
        int q = we;
        char t;
        while(p < q){
            t = A[p];
            A[p] = A[q];
            A[q] = t;
            p++;
            q--;
        }
    }

    // now reverse the entire string
    int p = 0;
    int q = A.length()-1;
    char t;
    while(p < q){
        t = A[p];
        A[p] = A[q];
        A[q] = t;
        p++;
        q--;
    };
}


int main(){

	string str;
	
	str="the sky is blue";
	cout<<str<<"\n";
	reverseWords(str);
	cout<<str<<"\n\n\n";
	
	str="j";
	cout<<str<<"\n";
	reverseWords(str);
	cout<<str<<"\n\n\n";

	str="   the    sky is        blue         ";
	cout<<str<<"\n";
	reverseWords(str);
	cout<<str<<"\n\n\n";

	str="   the    stock is  $100      high         ";
	cout<<str<<"\n";
	reverseWords(str);
	cout<<str<<"\n\n\n";

    return 0;
}

