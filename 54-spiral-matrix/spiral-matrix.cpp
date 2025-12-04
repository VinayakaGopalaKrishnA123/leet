class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> a;
        int left=0,right=matrix[0].size(),up=0,bo=matrix.size();
        int n=right*bo;
        int i=0,j=0;
        int tn=0;
        while(true){
            while(j<right){
                a.push_back(matrix[i][j]);
                // cout<<i<<" "<<j<<"\n";
                j++;
                tn++;
            }
            j--;
            i++;
            if(tn==n) break;
            while(i<bo){
                a.push_back(matrix[i][j]);
                // cout<<i<<" "<<j<<"\n";
                i++;
                tn++;
            }
            i--;
            j--;
            if(tn==n) break;
            while(j>=left){
                a.push_back(matrix[i][j]);
                // cout<<i<<" "<<j<<"\n";
                j--;
                tn++;
            }
            j++;
            i--;
            if(tn==n) break;
            while(i>up){
                a.push_back(matrix[i][j]);
                // cout<<i<<" "<<j<<"\n";
                i--;
                tn++;
            }
            i++;
            j++;
            if(tn==n) break;
            up++;bo--;right--;left++;
        }
        return a;
    }
};