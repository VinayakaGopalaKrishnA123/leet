class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> v(s.size());
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(st.size()==0){
                    v[i]=-1;
                }
                else if(st.size()>0){
                    v[i]=st.top();
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
        int ans=0;
        vector<pair<int,int>> anv;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' && v[i]!=-1){
                anv.push_back({v[i],i});
            }
        }
        vector<pair<int,int>> merged;
        sort(anv.begin(),anv.end());
        for(auto p:anv){
            if(merged.empty() || p.first>merged.back().second+1){
                merged.push_back(p);
            }
            else{
                merged.back().second=max(merged.back().second,p.second);
            }
        }
        for(auto p:merged){
            ans=max(ans,p.second-p.first+1);
        }
        return ans;
    }
};