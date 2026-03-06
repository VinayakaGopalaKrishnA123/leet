class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        while(s[i]=='1'){
            i++;
        }
        for(int j=i+1;j<s.size();j++){
            if(s[j]=='1') return false;
        }
        return true;
    }
};