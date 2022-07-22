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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        bool bo=1;
        ListNode* tmp=head;
        while(bo){
            ListNode* tt=tmp;
            int gaya=0;
            while(tt->next)
            {
                if(tt->val >= x and tt->next->val < x){
                     swap(tt->val,tt->next->val);
                     gaya=1;
                }
                tt=tt->next;   
            }
            bo=gaya;  
        }
        return head;
    }
};