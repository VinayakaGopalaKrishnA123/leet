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
    vector<string> v;
    void f(string s,TreeNode* root){
        if(root->left==nullptr && root->right==nullptr){
            v.push_back(s);
            return;
        }
        if(root->left!=nullptr) f(s+to_string(root->left->val),root->left);
        if(root->right!=nullptr) f(s+to_string(root->right->val),root->right);
    }
    int ff(string s){
        int ans=0;
        for(auto i:s){
            ans=ans*2+(i-'0');
        }
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        f(""+to_string(root->val),root);
        int ans=0;
        for(auto i:v){
            ans+=ff(i);
        }
        return ans;
    }
};