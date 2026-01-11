class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> m;
        long long ans=0;
        m[words[0]]++;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<26;j++){
                string s="";
                for(int k=0;k<words[i].size();k++){
                    char c=words[i][k]-j;
                    if(c<'a') c+=26;
                    s+=c;
                }
                // cout<<s<<' '<<m[s]<<'\n';
                ans+=m[s]*1ll;
            }

            m[words[i]]++;
        }
        return ans;
    }
};