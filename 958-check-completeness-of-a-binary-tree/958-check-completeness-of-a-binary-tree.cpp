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
    bool dodfs(TreeNode* root,int &height,int curr,bool &lessfnd){
        if(!root){ 
            cout<<curr<<" ";
            if(height==-1){
                height=curr;
                return 1;
            }else{
                 if(lessfnd){ 
                     if((curr+1)==(height)) return 1;
                     else return 0;
                 }else{
                     if(height==curr) return 1;  
                     else if(height == (curr+1)){
                         lessfnd=1;
                         return 1;
                     }else{
                         return 0;
                     }
                 }
            }
        } 
        if(!dodfs(root->left,height,curr+1,lessfnd) or !dodfs(root->right,height,curr+1,lessfnd)){
                return 0;
            }
        return 1;
    } 
    bool isCompleteTree(TreeNode* root) {
        int height=-1;
        bool lessfnd=0;     
       return dodfs(root,height,0,lessfnd);    
    }
};