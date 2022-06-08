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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> all;
        
        for (auto &i : lists)
            while (i)
            {
                all.push_back(i -> val);
                i = i -> next;
            }
        
        sort(all.begin(), all.end());
        
        if (all.size() < 1)
            return NULL;
        ListNode* ans = new ListNode(all[0]);
        ListNode* tmp = ans;
        
        for (int i = 1; i < all.size(); ++i)
        {
            tmp -> next = new ListNode(all[i]);
            tmp = tmp -> next;
        }
        
        return ans;
    }
};