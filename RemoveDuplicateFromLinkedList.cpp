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
     ListNode *del(ListNode *head)
    {  
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
         
         auto prv =new ListNode(-1);
         auto nextt =prv;
         
        while(head!=NULL)
        {
            if(head->next!=NULL && head->val == head->next->val)
            {
                
               int current =head->val;
              //skip all node with that val;
                while(head && head->val ==current)
                {
                     head =head->next;
                }
               
            }
            else
            { 
                // add node to next list i.e which not contain duplicate 
                // and move head;
              nextt->next =head;
              nextt =nextt->next;
                
              head =head->next;
            }
            
           
        }
         
         nextt->next=NULL;
         
        return prv->next;
    }
    ListNode* deleteDuplicates(ListNode* head) 
    {
         return del(head);
    }
};
