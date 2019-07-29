/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<iostream>
#include<vector>
using namespace std;


vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int i=0,j=0;
	int rows=A.size();
	int columns=A[0].size();
	int lowr=-1,lowc=-1,highr=rows,highc=columns;
	int total=rows*columns;
	while(1){
	    //cout<<"new\n";

	       // taking them to zero
	       lowr++;
	       lowc++;

	       // permissible
	       highr--;
	       highc--;

	       // start exe
	       i=lowr;
	       j=lowc;

	       if(lowr==(((rows-1)/2)+1)){
	          // cout<<"rows is "<<rows<<"\t and lowr is "<<lowr<<"\n";
	       //    cout<<"break1";
	           break;
	       }
	       if(lowc==(((columns-1)/2)+1)){
	           break;
	         //  cout<<"break2";
	       }


	       if(total && j<=highc){
    	        while(j<=highc){
    	          // cout<<"while1";
        	       result.push_back(A[i][j]);
        	       total--;
        	       j++;
        	   }
        	   j--;
	       }
	       //i++;
	       if(total && i<=highr){
	           i++;
    	       while(i<=highr){
        	    //   cout<<"while2";
        	       result.push_back(A[i][j]);
        	       total--;
        	       i++;
        	   }
        	   i--;
        	}
    	   if(total && j>=lowc){
        	      j--;
        	     while(j>=lowc){
        	    //   cout<<"while3";
        	       result.push_back(A[i][j]);
        	       total--;
        	       j--;
        	    }
        	    j++;
    	   }
    	   //i--;
    	   if(total && i>=(lowr+2)){
    	       i--;
        	   while(i>=(lowr+1)){
        	    //   cout<<"while4";
        	       result.push_back(A[i][j]);
        	       total--;
        	       i--;
        	       //i--;
        	   }
    	   }
	}
	return result;
}


int main(){

	vector<vector<int>> arr({
		{1,2,3},
		{8,9,4},
		{7,6,5}
	});
	vector<int> res;
	res=spiralOrder(arr);

	for(int i=0;i<res.size();++i){
		cout<<res[i]<<" ";
	}


    return 0;
}

