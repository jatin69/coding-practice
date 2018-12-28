
// initial solution

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res = {{}} ;
        int noOfSets = pow(2, nums.size())-1;
         
        // to generate sets
        vector<bool> track(nums.size());
        
        while(noOfSets--){
            
            // make a subset
            for(int i=nums.size()-1; i>=0; --i){
                if(track[i]){
                    track[i] = false;
                }
                else{
                    track[i] = true;
                    break;
                }
            }
            
            
            // add this subset
            vector<int> temp;
            for(int i=0;i<nums.size();++i){
                if(track[i]){
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};



// Better Solution

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        int limit = (1<<n);
    
        for(int i = 0; i<limit; ++i) {
            vector<int> t;
            for(int j = 0; j<n; ++j){
                if(i&(1<<j)){
                    t.push_back(nums[j]);
                }
            }
            res.push_back(t);
        }
        return res;
        
    }
};