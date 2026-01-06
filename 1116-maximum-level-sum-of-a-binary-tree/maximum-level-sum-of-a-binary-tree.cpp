/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*> q;
       int ms=root->val;
       int l=1;
       int le=0;
       q.push(root);
       while(!q.empty()){
            int sum=0;
            int sz = q.size();
            le++;
            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();
                sum+=cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            // cout<<sum<<" "<<le<<"\n";
            if(sum>ms){
                ms=sum;
                l=le;
            }
       }
       return l;
    }
};