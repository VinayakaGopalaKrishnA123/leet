class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inp(numCourses);
        vector<vector<int>> adjm(numCourses);
        for(auto i:prerequisites){
            adjm[i[1]].push_back(i[0]);
            inp[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<inp.size();i++){
            if(inp[i]==0) q.push(i);
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto i:adjm[a]){
                inp[i]--;
                if(inp[i]==0) q.push(i);
            }
        }
        for(int i=0;i<inp.size();i++){
            if(inp[i]!=0) return false;
        }
        return true;
    }
};