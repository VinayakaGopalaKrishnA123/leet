class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char,int> m;
        int c=0,j=0;
        for(auto i:s){
            m[i]++;
            j++;
            if(j%3==m.size()) c++;
        }
        return c;
    }
};