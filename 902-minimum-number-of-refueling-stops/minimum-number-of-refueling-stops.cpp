class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int t=startFuel;
        int ans=0;
        for(int i=0;i<stations.size();i++){
            // cout<<t<<' ';
            while(t<stations[i][0]){
                if(pq.size()==0) return -1;
                else{
                    t+=pq.top();
                    pq.pop();
                    ans++;
                }
            }
            pq.push(stations[i][1]);
        }
        while(!pq.empty() && t<target){
            t+=pq.top();
            pq.pop();
            ans++;
        }
        if(t<target) return -1;
        return ans;
    }
};