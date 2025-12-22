class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int,vector<int>> rm;
        unordered_map<int,int> rmi;//rows conditions map on indegree;
        queue<int> rq;
        vector<int> ro;//row order
        for(int i=1;i<=k;i++) rmi[i]=0;
        for(auto i:rowConditions){
            rm[i[0]].push_back(i[1]);
            rmi[i[1]]++;
        }
        for(auto i:rmi){
            if(i.second==0){
                rq.push(i.first);
            }
        }
        while(!rq.empty()){
            int top = rq.front();
            ro.push_back(top);
            for(auto i: rm[top]){
                if(--rmi[i]==0) rq.push(i);
            }
            rq.pop();
        }
        unordered_map<int,vector<int>> cm;
        unordered_map<int,int> cmi;//column conditions map on indegree;
        queue<int> cq;
        vector<int> co;//col order
        for(int i=1;i<=k;i++) cmi[i]=0;
        for(auto i: colConditions){
            cm[i[0]].push_back(i[1]);
            cmi[i[1]]++;
        }
        for(auto i:cmi){
            if(i.second==0){
                cq.push(i.first);
            }
        }
        while(!cq.empty()){
            int top = cq.front();
            co.push_back(top);
            for(auto i: cm[top]){
                if(--cmi[i]==0) cq.push(i);
            }
            cq.pop();
        }
        unordered_map<int,int> ri;//row element indexes
        unordered_map<int,int> ci;//col element indexes
        for(int i=0;i<ro.size();i++){
            ri[ro[i]]=i;
        } 
        for(int i=0;i<co.size();i++){
            ci[co[i]]=i;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[ri[i]][ci[i]]=i;
        }
        if(ro.size()!=k || co.size()!=k) return {};
        return ans;
    }
};