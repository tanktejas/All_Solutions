/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1=headA;
        ListNode* h2=headB;
        
        int tra=0;
        
        while(h1!=h2){
        
           if(h1->next==NULL){
               h1=headB;
               if(tra==1) return NULL;
               tra++;
           }else{
               h1=h1->next;   
           }
            
           if(h2->next==NULL){
               h2=headA;
           }else{
               h2=h2->next;
           }
        }
        
        return h1;
    }
};