class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int a=points[0][0],b=points[0][1];
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=b){
                b=min(points[i][1],b);
            }
            else{
                ans++;
                a=points[i][0];
                b=points[i][1];
            }
        }
        return ans;
    }
};