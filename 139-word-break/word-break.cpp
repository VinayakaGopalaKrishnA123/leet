class Solution {
public:
    unordered_map<string,int> m;
    unordered_map<string,bool> dp;
    bool f(string s,string te,int ind){

        if(ind>=s.size() && te=="") return true;
        if(ind>=s.size() ) return false;
        string key= to_string(ind)+"#"+te;
        if(dp.find(key)!=dp.end()) return dp[key];
        bool pick=false;
        if(m.find(te+s[ind])!=m.end()){
            pick=f(s,"",ind+1);
        }
        bool notpick=f(s,te+s[ind],ind+1);
        return dp[key]=(pick||notpick);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i: wordDict){
            m[i]=1;
        }
        // f(s,"",0);
        // for(auto i : dp ){
        //     cout<<i.first<<' '<<i.second<<'\n';
        // }

        return f(s,"",0);
    }


     
};