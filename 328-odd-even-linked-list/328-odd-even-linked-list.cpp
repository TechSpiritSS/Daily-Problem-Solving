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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next)
            return head;
        
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* oh = odd;
        ListNode* eh = even;
        bool flag = true;
        
        while (head)
        {
            if (flag)
            {
                odd -> next = head;
                odd = odd -> next;
            }
            else
            {
                even -> next = head;
                even = even -> next;
            }
            
            flag = !flag;
            head = head -> next;
        }

        head = oh -> next;
        odd -> next = eh -> next;
        even -> next = NULL;

        return head;
    }
};