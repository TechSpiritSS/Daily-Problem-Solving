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
    ListNode *h;
    
public:
    Solution(ListNode* head) {
        h = head;
        srand (time(NULL));
    }
    
    int getRandom() {
        int random = 1,
            ans = 0;
        
        ListNode* x = h;
        
        while (x)
        {
            if (rand() % random == 0)
                ans = x -> val;
            
            ++random;
            x = x -> next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */