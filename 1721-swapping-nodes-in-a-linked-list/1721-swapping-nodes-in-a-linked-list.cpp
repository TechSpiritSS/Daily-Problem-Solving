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
    ListNode* swapNodes(ListNode* head, int k) {
        int count =  0;
        ListNode* tmp = head;
        
        while (tmp)
        {
            count++;
            tmp = tmp -> next;
        }
        
        int back = count - k;
        
        tmp = head;
        ListNode* s1 = NULL;
        
        --k;
        while (k)
        {
            --k;
            tmp = tmp -> next;
        }
        
        s1 = tmp;
        tmp = head;
        
        while (back)
        {
            --back;
            tmp = tmp -> next;
        }
        
        swap(tmp -> val, s1 -> val);
        
        return head;
    }
};