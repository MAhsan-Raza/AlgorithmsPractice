/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
private:
    ListNode* Prev;
    
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head) return Prev;

        ListNode* scnd = head->next;
        head->next = Prev;
        Prev = head;
        return reverseList(scnd);
    }
    
    Solution() : Prev(nullptr) {}
};
