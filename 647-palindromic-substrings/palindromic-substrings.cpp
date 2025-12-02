class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> v(s.size(),vector<int>(s.size()));
        for(int i=0;i<s.size();i++) v[i][i]=1;
        int mi=0,mj=1;
        int cnt=s.size();
        while(mj<s.size()){
            int ti=0,tj=mj;
            while(tj<s.size()){
                if(tj-ti==1){
                    if(s[ti]==s[tj]){
                        v[ti][tj]=1;
                        cnt++;
                    }
                }
                else if(s[ti]==s[tj] && v[ti+1][tj-1]==1){
                    v[ti][tj]=1;
                    cnt++;
                } 
                ti++;
                tj++;
            }
            mj++;
        }
        return cnt;
    }
};