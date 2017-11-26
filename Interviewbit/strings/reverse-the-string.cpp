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

void reverseWords(string &A) {
    string res="";
    int size=A.length();
    for(int i=0;i<size;++i){
		string word="";
        while(i<size && A[i]==' '){ i++; }

        while(i<size && A[i]!=' '){
            word.push_back(A[i]);
            i++;
        }
        i--;
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

