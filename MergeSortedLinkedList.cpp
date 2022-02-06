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
class Solution 
{
public:
    /*
    
       ListNode* merge(ListNode* list1 ,ListNode* list2)
       {
            if(list1 == nullptr)
            {
               return list2;
            }
            if(list2 == nullptr)
            {
             return list1;
            }
          ListNode dhead(INT_MIN);
         ListNode* head = &dhead;
        
        // mearge sort logic
        while(list1!=NULL && list2!=NULL)
        {
            
            if(list1->val < list2->val)
            {
                head->next =new ListNode(list1->val);
                list1=list1->next;
                head=head->next;
            }
            else
            {
                head->next =new ListNode(list2->val);
                list2=list2->next;
                head =head->next;
            }
            
        }
        // if any list remain to copy
        head->next =list1?list1:list2;
        //head->next=NULL;
        return dhead.next;
    
       }*/
    
    ListNode* merge(ListNode* list1 ,ListNode* list2)
       {
            if(list1 == nullptr)
            {
               return list2;
            }
            if(list2 == nullptr)
            {
             return list1;
            }
        
            if(list1->val <= list2->val)
            {
                list1->next =merge(list1->next,list2);
                return list1;
            }
            else
            {
                list2->next =merge(list1,list2->next);
                return list2;
            }
    }
        
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    { 
        
        if(lists.size()==0)
        {
            return NULL;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }
        ListNode* mainhead = merge(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++)
        {
            mainhead = merge(mainhead ,lists[i]);
        }
        return mainhead;
    }
};
