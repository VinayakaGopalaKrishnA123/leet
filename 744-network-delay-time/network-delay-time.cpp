class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> v(n+1,INT_MAX);
        v[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto j:adj[u]){
                if(d+j.second<v[j.first]){
                    v[j.first]=d+j.second;
                    pq.push({v[j.first],j.first});
                }
            }
        }
        int ans=v[1];
        for(int i=2;i<=n;i++){
            ans=max(ans,v[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};