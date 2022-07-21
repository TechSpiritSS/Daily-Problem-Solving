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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head)
            return NULL;
        
        ListNode* curr = head, *prev = NULL;
        
        while (left > 1)
        {
            prev = curr;
            curr = curr -> next;
            --left;
            --right;
        }
        
        ListNode* leftNode = prev, *tail = curr, *nextNode = NULL;
        
        while (right > 0)
        {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
            --right;
        }
        
        if (leftNode)
            leftNode -> next = prev;
        else
            head = prev;
        
        tail -> next = curr;
        return head;
    }
};