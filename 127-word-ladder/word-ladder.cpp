class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m,vis;
        for(auto i: wordList) m[i]=1;
        // if(m.find(endWord)==m.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            int qs=q.size();
            level++;
            for(int i=0;i<qs;i++){
            string temp=q.front();
            q.pop();
            for(int i=0;i<beginWord.size();i++){
                char tt=temp[i];
                for(int j=0;j<26;j++){
                    if('a'+j!=tt) temp[i]='a'+j;
                    if(temp==endWord && m.find(temp)!=m.end()) return level;
                    if(m.find(temp)!=m.end() && vis[temp]==0){ q.push(temp); vis[temp]=1;}
                }
                temp[i]=tt;
            }
            }
        }
        return 0;
    }
};