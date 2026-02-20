class Solution {
public:
    int countBinarySubstrings(string s) {
        int r=0,prev=0,ss=1;
        for (int i=1;i<s.size();i++) {
            if (s[i]==s[i-1]) ss++;
            else {
                prev=ss;
                ss=1;
            }
            if (ss<=prev)r++;
        }
        return r;
    }
};
