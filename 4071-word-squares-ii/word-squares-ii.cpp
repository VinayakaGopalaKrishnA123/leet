class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> pick(int n){    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==i||k==j) continue;
                    for(int l=0;l<n;l++){
                        if(l==i||l==j||l==k) continue;
                        v.push_back({i,j,k,l});
                    }
                }
            }
        return v;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        pick(words.size());
        vector<vector<string>> ans;
        for(auto i:v){
            string t=words[i[0]];
            string l=words[i[1]];
            string r=words[i[2]];
            string b=words[i[3]];
            if(t[0]==l[0] && t[3]==r[0] && b[0]==l[3] && b[3]==r[3]){
                ans.push_back({t,l,r,b});
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};