class Solution {
public:
    int reverseBits(int n) {
        int s = 0;
        for(int i=0;i<32;i++){
            s+=(1<<(31-i))*(n&1);
            n>>=1;
        }
        return s;
    }
};
