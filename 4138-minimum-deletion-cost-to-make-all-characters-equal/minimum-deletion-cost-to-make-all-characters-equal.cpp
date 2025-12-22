class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long> m;
        long long ts=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]+=cost[i];
            ts+=cost[i];
        }
        long long ans=LLONG_MAX;
        for(auto i:m){
            // cout<<i.first<<" "<<i.second<<'\n';
            ans=min(ans,ts-i.second);
        }
        return ans;
    }
};