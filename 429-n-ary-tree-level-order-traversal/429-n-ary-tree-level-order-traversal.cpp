/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>>ans;
        vector<int>tm;
       
        if(!root) return {};
       
        ans.push_back({root->val});
        
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=1){
            if(q.front()==NULL){
                ans.push_back(tm);
                q.pop();  
                tm.clear();
                q.push(NULL);
            }
            auto tt=q.front();
            q.pop();
            
            for(int i=0;i<tt->children.size();i++)
            {
                q.push(tt->children[i]);
                tm.push_back(tt->children[i]->val);
            }
            
        }
        
        return ans;
    }
};