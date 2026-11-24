class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> v(n);
        vector<int> dis(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        for(auto i:flights){
            v[i[0]].push_back({i[1],i[2]});
        }
        int level=0;
        while(!q.empty() && level<=k){
            int qs=q.size();
            while(qs--){
                auto[so,pr]=q.front();
                q.pop();
                for(auto i:v[so]){
                    if(pr+i.second<dis[i.first]){
                        q.push({i.first,pr+i.second});  
                        dis[i.first]=pr+i.second;
                    }
                }
                
            }
            level++;
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};