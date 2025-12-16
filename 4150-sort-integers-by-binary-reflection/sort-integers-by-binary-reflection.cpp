class Solution {
public:
    int f(int x) {
        int r = 0;
        while (x > 0) {
            r = (r << 1) | (x & 1);
            x >>= 1;
        }
        return r;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int ta=f(a),tb=f(b);
            if(ta==tb) return a<b;
            return ta<tb;
        });
        return nums;
    }
};