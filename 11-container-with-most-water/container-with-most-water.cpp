class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int l=0,r=height.size()-1;
        while(l<r){
            // cout<<(r-l)<<min(height[r],height[l]);
            ans=max(ans,(r-l)*min(height[r],height[l]));
            if(height[r]>height[l]) l++;
            else r--;
        }
        return ans;

    }
};