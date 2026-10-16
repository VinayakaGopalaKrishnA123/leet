class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans,v(numCourses,0);
        vector<vector<int>>adj(numCourses);
        queue<int> q;
        for(auto i:prerequisites){
            v[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(v[i]==0) q.push(i);
        }
        int t=0;
        while(!q.empty()){
            int f=q.front();
            t++;
            ans.push_back(f);
            for(auto i: adj[f]){
                v[i]--;
                if(v[i]==0) q.push(i);
            }
            q.pop();
        }
        if(t!=numCourses) return {};
        return ans;
    }
};