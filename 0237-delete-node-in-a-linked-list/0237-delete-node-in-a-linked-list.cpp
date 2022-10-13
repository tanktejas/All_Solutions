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
    void deleteNode(ListNode* node) {
       
        ListNode* yy=node;
        
        while(node->next)
        {
            yy=node;
            node->val=node->next->val;
            node=node->next;
        }
         
        yy->next=NULL;
    }
};