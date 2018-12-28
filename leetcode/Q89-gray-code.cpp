
// initial solution

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        
        vector<int> res = {0, 1};
        int bitlen = 2;
        while(bitlen <= n){
            int j = res.size()-1;
            int addOneToLeft = (1<<(bitlen-1));
            while(j>=0){
              res.push_back((res[j] | addOneToLeft));
              j--;
            }
            bitlen++;
        }
        
        return res;
    }
};

/*

Intuition -

0
1

next iteration - 

0
1
reverse and add 1 to leftmost
11
10


*/


//  better solution

class Solution {
public:
    vector<int> grayCode(int n) {
        int noOfElements = (1 << n); 
        vector<int> ans(noOfElements);
        for (int i = 0; i < noOfElements; ++i) 
            ans[i] = i ^ (i >> 1);
        return ans;
    }
};
