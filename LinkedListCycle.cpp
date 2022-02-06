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
    ListNode *detectCycle(ListNode *head)
    {
        
        //flyod detection cycle
         
        ListNode *slow =head;
        ListNode *fast =head;
        
        while(fast && fast->next)
        {
            slow =slow->next;
            fast=fast->next->next;
            if(slow==fast)   // cycle detected
            {   
                if(slow==head)
                {
                    return slow;
                }
                
               slow =head;
                while(fast->next !=slow->next)
               {
                   slow=slow->next;
                   fast=fast->next;
               }
                
                return slow->next;
            }
        }
        
        return NULL;
    }
};
