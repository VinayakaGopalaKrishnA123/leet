class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int md=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            md=min(arr[i+1]-arr[i],md);
        }
        vector<vector<int>> ans;
        cout<<md;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==md) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};