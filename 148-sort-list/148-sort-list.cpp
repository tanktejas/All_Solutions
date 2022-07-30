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
    ListNode* sortList(ListNode* head) {
        int len=0;
        ListNode* uu=head;
        
        if(!head) return head;
        
        while(uu){
            uu=uu->next;
            len++;
        }
        
        int gap=ceil((len+1)/2);
         
        while(gap>0)
        { 
            bool bo=0;
            
            ListNode* t1=head;
            ListNode* t2=head;
            int cnt=gap;
            
            while(cnt--)
            {
                t2=t2->next;
            }
            
            while(t2!=NULL)
            {
                if(t1->val > t2->val)
                {
                    swap(t1->val,t2->val);
                    bo=1;
                }
                t1=t1->next;
                t2=t2->next;
            }
            
            if(!bo)
             gap=ceil(gap/2);
            
        }
         
        return head;
    }
}; 