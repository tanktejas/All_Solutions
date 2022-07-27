/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void find(Node* head)
    {
        if(!head) return ;
        
        if(head->child != NULL){
             
             find(head->child);
             
             Node* f=head->child;
             Node* l=head->child;
             head->child=NULL;
            
             while(l and l->next) l=l->next;
            
             Node* hne=head->next;
                
                 head->next=f;
                 f->prev=head;
                 l->next=hne;
                 
             if(hne){
                hne->prev=l; 
             }
             
        } 
        
        find(head->next);
        
    }
    
    
    Node* flatten(Node* head) {
        find(head);
 
        return head;
    }
};