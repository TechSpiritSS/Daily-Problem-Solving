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
    int count(ListNode* head)
    {
        int c = 0;
        
        while (head)
        {
            c++;
            head = head->next;
        }
        
        return c;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int l = count(head);
        l /= 2;
        
        while (l--)
            head = head -> next;        
        
        return head;
    }
};