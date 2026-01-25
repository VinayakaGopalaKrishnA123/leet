class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> v;
        vector<int> vi;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>-1){
                v.push_back(nums[i]);
                vi.push_back(i);
            }
        }
        if(v.size()==0) return nums;
        for(auto i:v) cout<<i<<' ';
        k=k%v.size();
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
        reverse(v.begin(),v.end());
        for(int i=0;i<vi.size();i++){
            nums[vi[i]]=v[i];
        }
        return nums;
    }
};