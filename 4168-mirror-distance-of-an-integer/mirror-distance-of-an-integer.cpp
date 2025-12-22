class Solution {
public:
    int r(int n){
        int tn=0;
        while(n>0){
            int m=n%10;
            tn=tn*10+m;
            n/=10;
        }
        return tn;
    }
    int mirrorDistance(int n) {
        return abs(n-r(n));
    }
};