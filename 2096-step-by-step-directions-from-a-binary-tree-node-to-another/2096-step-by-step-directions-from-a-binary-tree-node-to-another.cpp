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
       TreeNode* lca;
    
       bool find(TreeNode* root,int &p,int &q){
        if(!root) return 0;
        
        if(!root->left and !root->right) return (p==root->val or q==root->val);
        
       bool l=find(root->left,p,q);
       bool r=find(root->right,p,q);
        
        if(l and r){
            lca=root;
            return 0;
        }else if((l and (root->val==p or root->val==q )) or (r and (root->val==p or root->val==q))){
            lca=root;
            return 0;
        }  
     
        
        if(root->val==p or root->val==q) return 1;
        
        return l or r;
        
    } 
    
    void findpath(TreeNode* root,int &sv,int &ev,string &lans,string &rans,string &curr){
        if(!root or (lans!="" and rans!="")) return ;
        
        if(root->val == sv){
            lans=curr;
            if(lca!=root) return ;
        }else if(root->val == ev){
            rans=curr;
            if(lca!=root) return ;
        }
        
        curr+="L";
        findpath(root->left,sv,ev,lans,rans,curr);
        curr.pop_back();
        curr+="R";
        findpath(root->right,sv,ev,lans,rans,curr);
        curr.pop_back();
        
    }
    
    
    string getDirections(TreeNode* root, int sv, int ev) {
        find(root,sv,ev);
        
        string lans="";
        string rans="";
        
        string path="";
        findpath(lca,sv,ev,lans,rans,path);
        
        for(int i=0;i<lans.length();i++){
            rans="U"+rans;
        } 
        
        return rans;
    }
};