class Solution {
public:
    int tn;
    vector<vector<int>> dp;
    int f(int ta,vector<int> &sq,int ind){
        if(ta>tn || ind>=sq.size()) return INT_MAX;
        if(ta==tn) return 0;
        if(dp[ta][ind]!=-1) return dp[ta][ind];
        int take=f(ta+sq[ind],sq,ind);
        if(take!=INT_MAX) take+=1;
        int nottake=f(ta,sq,ind+1);
        return dp[ta][ind]=min(take,nottake);
    }
    int numSquares(int n) {
        tn=n;
        vector<int> squares;
        for(int i=1;i*i<=n;i++){
            squares.push_back(i*i);
        }
        dp.resize(n+1,vector<int>(squares.size(),-1));
        return f(0,squares,0);
    }
};