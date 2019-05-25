/*
 * Author : Jatin Rohilla
 * Date   : 2019
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++14
 *
 */


#include<bits/stdc++.h>
using namespace std;

string extract(int &i, string str){
    if(i >= str.size()){
        return "0";
    }
    int temp = i;
    stringstream ss;
    ss.str("");
    while(str[temp] != '.' && temp < str.size()){
        ss << str[temp];
        temp++;
    }
    i = temp + 1;

    return ss.str();
}

string rem(string a){
    int i = 0;
    while(a[i] == '0' && i < a.size()){
        i++;
    }

    return a.substr(i);
}

int compareStr(string a, string b, int first){

    string A = rem(a);
    string B = rem(b);

    if(A.size() > B.size()){
        return 1;
    }
    else if(A.size() < B.size()){
        return -1;
    }
    else{
        for(int i = 0; i < A.size(); i++){
            int numa = A[i];
            int numb = B[i];
            if(numa > numb){
                return 1;
            }
            else if(numa < numb){
                return -1;
            }
        }
    }

    return 0;
}

int Solution::compareVersion(string A, string B) {
    int i = 0, j = 0, first = 1;
    while(i < A.size() || j < B.size()){
        string numa = extract(i, A);
        string numb = extract(j, B);
        if(compareStr(numa, numb, first) == 1){
            return 1;
        }
        else if(compareStr(numa, numb, first) == -1){
            return -1;
        }
        first = 0;
    }
    return 0;
}


int main(){

	cout<<"Hello World";

    return 0;
}


// mine
int Solution::compareVersion(string A, string B) {

    int i=0;
    int j=0;

    while(i<A.length() || j<B.length()){

        unsigned long long int da = 0;
        while(i<A.length() && A[i]>='0' && A[i]<='9'){
            da = da*10 + (A[i]-'0');
            i++;
        }
        unsigned long long int db = 0;
        while(j<B.length() && B[j]>='0' && B[j]<='9'){
            db = db*10 + (B[j]-'0');
            j++;
        }

        // cout << "da is " << da << " and db is " << db << " ";
        if(da > db){
            return 1;
        }
        else if(da < db){
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}
