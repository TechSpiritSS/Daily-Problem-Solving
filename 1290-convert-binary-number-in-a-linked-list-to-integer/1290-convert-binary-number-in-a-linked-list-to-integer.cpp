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
    int getDecimalValue(ListNode* head) {
        string bin = "";
        
        while (head)
        {
            bin += ('0' + head -> val);
            head = head -> next;
        }
        
        int ans = 0;
        int pow = 1;
        
        for (int i = bin.size() - 1; i >= 0; --i)
        {
            ans += (bin[i] - '0' )* pow;
            pow *= 2;
        }
        
        return ans;
    }
};