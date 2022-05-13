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
        Node* curr=root;
        
        while(curr!=NULL){
             Node* dumm=new Node(0);
             Node* nextpass=dumm;
            while(curr){
                  if(curr->left){
                      dumm->next=curr->left;
                      dumm=dumm->next;
                  }
                
                   if(curr->right){
                      dumm->next=curr->right;
                      dumm=dumm->next;      
                   }
                curr=curr->next;
            } 
           curr=nextpass->next;
        } 
        return root;
    }
};