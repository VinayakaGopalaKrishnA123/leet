/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root,TreeNode* e,vector<TreeNode*> &t){
        if(root==e) {t.push_back(e); return true;}
        if(root==NULL) return false;
        if(dfs(root->left,e,t) || dfs(root->right,e,t)){
            t.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        dfs(root,p,a);
        dfs(root,q,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        TreeNode* ans=a[0];
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i]) ans=a[i];
        }
        return ans;
    }
};