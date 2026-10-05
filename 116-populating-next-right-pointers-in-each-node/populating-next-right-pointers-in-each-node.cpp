/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* temp=root;
        stack<Node *> st;
        queue<Node *> q;
        if(root){ st.push(root); q.push(root);}
        while(!st.empty()){
            int n=st.size();
            Node *tt=NULL;
            for(int i=0;i<n;i++){
                st.top()->next=tt;
                tt=st.top();
                st.pop();
            }
            for(int i=0;i<n;i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                    st.push(q.front()->left);
                    st.push(q.front()->right);
                }
                q.pop();
            }
        }
        return root;
    }
};