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
    bool isPalindrome(ListNode* head) 
    {
        bool bRes = true;
        if(!head || !head->next) return bRes;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr; 
        ListNode* revHead = Rev(mid, nullptr);
        
        ListNode* revCrnt = revHead;
        ListNode* root = head;
        while(revCrnt)
        {
            if(head->val != revCrnt->val)
            {
                bRes = false;
                break;
            }
            head = head->next;
            revCrnt = revCrnt->next;
        }
        return bRes;
    }
    
    inline 
    ListNode* Rev(ListNode* crnt, ListNode* prev)
    {
        ListNode* scnd = crnt->next;
        crnt->next = prev;
        if(!scnd)       return crnt;
        else            return Rev(scnd, crnt);
    }
};
