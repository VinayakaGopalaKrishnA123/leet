class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size()+1,vector<int> (word1.size()+1));
        for(int i=0;i<word1.size()+1;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<word2.size()+1;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<word2.size()+1;i++){
            for(int j=1;j<word1.size()+1;j++){
                if(word2[i-1]==word1[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int a=dp[i-1][j];
                    int b=dp[i][j-1];
                    int c=dp[i-1][j-1];
                    dp[i][j]=min(min(a,b),c)+1;
                }
            }
        }
        return dp[word2.size()][word1.size()];
    }
};