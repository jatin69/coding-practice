class Solution {
public:
    int minDistance(string word1, string word2) {
        
        // initiliase dp table
        int rows = word1.length();
        int columns = word2.length();
        vector<vector<int>> dp(rows+1, vector<int>(columns+1));
        
        // base cases
        for(int i=0; i<=rows; ++i) {
            dp[i][0] = i;    
        }
        for(int j=0; j<=columns; ++j) {
            dp[0][j] = j;    
        }
        
        for(int i=1; i<=rows; ++i) {
            for(int j=1; j<=columns; ++j) {
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[rows][columns];
    }
};