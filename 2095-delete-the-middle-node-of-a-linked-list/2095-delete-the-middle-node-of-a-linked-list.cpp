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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next==NULL) return NULL;
        
        int len=0;
        ListNode* hh=head;
        while(hh)
        {
             len++;
             hh=hh->next;
        }
        
        len=len/2;
        len--;
        
        ListNode* j=head;
        
        while(len--)
        {
            head=head->next;
        }
        head->next=head->next->next;
        
        return j;
    }
};