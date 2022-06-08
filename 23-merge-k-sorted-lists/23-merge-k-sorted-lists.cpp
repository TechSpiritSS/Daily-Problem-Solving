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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        if (l1 -> val < l2 -> val)
        {
            l1 -> next = merge(l1 -> next, l2);
            return l1;
        }
        
        l2 -> next = merge(l2 -> next, l1);
        return l2;
    }
    
    ListNode* mergedKLists(vector<ListNode*> &lists, int l, int r)
    {
        if (l > r)
            return NULL;
        if (l == r)
            return lists[l];
        
        int m = (l + r) / 2;
        
        ListNode* m1 = mergedKLists(lists, l, m), *m2 = mergedKLists(lists, m + 1, r);
        return merge(m1, m2);
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergedKLists(lists, 0, lists.size() - 1);
    }
};