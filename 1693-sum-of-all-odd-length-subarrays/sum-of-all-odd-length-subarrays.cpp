class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i]*ceil(((i+1)*1.0*(n-i))/2);
        }
        return sum;
    }
};