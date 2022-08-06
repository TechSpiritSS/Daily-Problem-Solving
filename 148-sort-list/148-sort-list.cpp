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
    ListNode* mid(ListNode* head)
    {
        ListNode* slow = NULL;
        
        while (head && head -> next)
        {
            slow = slow == NULL ? head : slow -> next;
            head = head -> next -> next;
        }
        
        ListNode* m = slow -> next;
        slow -> next = NULL;
        return m;
    }
    
    ListNode* merge(ListNode* l, ListNode* r)
    {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        
        while (l && r)
        {
            if (l -> val < r -> val)
            {
                tmp -> next = l;
                l = l-> next;
            }
            else
            {
                tmp -> next = r;
                r = r -> next;
            }
            tmp = tmp -> next;
        }
        
        if (l) tmp -> next = l;
        else tmp -> next = r;
        return head -> next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next)
            return head;
        
        ListNode* m = mid(head);
        ListNode* l = sortList(head);
        ListNode* r = sortList(m);
        return merge(l, r);
    }
};