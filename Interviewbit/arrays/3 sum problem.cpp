#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std; 
  

bool three_sum_prob(vector<int> A, int sum) 
{ 

  //sort the array.
    sort(A.begin(), A.end()); 
    int size=A.size();
    int l,r;
    
    for (int i = 0; i < size - 2; i++) { 
  
        
        l = i + 1; 
        r = size - 1; 
        while (l < r) { 
            if (A[i] + A[l] + A[r] == sum) { 
                cout<<"Triplet is "<< A[i]<<" "<<A[l]<<" "<<A[r]; 
                return true; 
            } 
            else if (A[i] + A[l] + A[r] < sum) 
                l++; 
            else 
                r--; 
        } 
    } 
  
    cout<<"No such Triplet Exist";
    return false; 
} 
  

int main() 
{ 
    vector<int> A;
    int sum, size;
    cout<<"Size: ";
    cin>>size;
    
    for(int i=0; i<size; i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    cout<<"sum: ";
    cin>>sum;
    three_sum_prob(A,sum); 
  
    return 0; 
} 
