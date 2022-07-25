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
    ListNode* middle(ListNode* h)
    {
        ListNode* fast = h;
        
        while (fast -> next && fast -> next -> next)
        {
            h = h -> next;
            fast = fast -> next -> next;
        }
        return h;
    }
    
    ListNode* reverse(ListNode* r)
    {
        if (!r || !r -> next)
            return r;
        
        ListNode* rev = NULL;
        
        while (r)
        {
            ListNode* tmp = r -> next;
            r -> next = rev;
            rev = r;
            r = tmp;
        }
        
        return rev;
    }
        
public:
    bool isPalindrome(ListNode* head) {
        ListNode* m = middle(head);
        ListNode* l2 = reverse(m -> next);
        
        while (head && l2)
        {
            if (head -> val != l2 -> val) return false;
            
            head = head -> next;
            l2 = l2 -> next;
        }
        return true;
    }
};