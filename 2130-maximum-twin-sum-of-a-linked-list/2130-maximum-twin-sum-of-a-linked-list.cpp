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
    int n = 0;
    ListNode* reverse(ListNode* head)
    {
        if(!head ||!head -> next) return head;
        ListNode *rest = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return rest;
    }

    ListNode* copyList(ListNode* head)
    {
        if (!head) return NULL;
        else 
        {
            ListNode* newNode = new ListNode();
            newNode -> val = head -> val;
            ++n;
            newNode -> next = copyList(head -> next);
            return newNode;
        }
    }
    
public:
    int pairSum(ListNode* head) {

        ListNode* rev = copyList(head);
        rev = reverse(rev);
        int maxi = 0;
        n = n/2;
        
        while (n--)
        {
            int sum = head -> val + rev -> val;
            head = head -> next;
            rev = rev -> next;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};