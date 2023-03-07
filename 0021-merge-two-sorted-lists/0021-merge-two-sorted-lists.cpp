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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *ans = head;
        
        while (list1 || list2)
        {
            if (!list1 || (list2 && list2 -> val < list1 -> val))
            {
                ans -> next = list2;
                list2 = list2 -> next;
            }
            else
            {
                ans -> next = list1;
                list1 = list1 -> next;
            }
            ans = ans -> next;
        }
        
        return head -> next;
    }
};