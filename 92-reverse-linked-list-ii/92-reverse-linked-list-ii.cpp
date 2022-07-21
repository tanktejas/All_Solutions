/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* op=NULL;
    
    ListNode* find(ListNode* head,int ct)
    {  
        if(head==NULL or head->next==NULL or ct==0){
           if(head)
            op=head->next;
           else 
            op=head;
            return head;
        }
        
        ListNode* ii=find(head->next,ct-1);
   
            ListNode* tt=head->next;
            tt->next=head;
            head->next=NULL;  
            return ii;  
         
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int curr=0;
        
        if(head->next==NULL) return head;
        
        if(left==right) return head;
        
          if(left==1){
            ListNode* io=head;    
            ListNode* pp=find(head,right-left); 
            io->next=op;
            return pp;  
        }
        
        
        int tt=1;
        ListNode* tmp=head;
        while((tt+1)!=left){
            tmp=tmp->next;
            tt++;
        }
         
        cout<<tmp->val;
        
        ListNode* io=tmp->next;
        tmp->next= find(tmp->next,right-left); 
        
        if(io){
           io->next=op;  
        } 
        
        return head;
    }
};