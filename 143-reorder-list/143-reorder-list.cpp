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
    ListNode *reverse(ListNode *head) {
		if (!head || !head->next) return head;
		
        ListNode *rev = reverse(head -> next);
		head -> next -> next = head;
		head -> next = nullptr;
		return rev;
	}

public:
	void reorderList(ListNode *head) {
		ListNode *slow = head, *fast = head;
        
		while (fast && fast -> next) {
			slow = slow -> next;
			fast = fast -> next -> next;
		}

		fast = reverse(slow -> next);
		slow -> next = nullptr;

		while (fast) {
			ListNode *temp = fast -> next;
			fast -> next = head -> next;
			head -> next = fast;
			head = fast -> next;
			fast = temp;
		}
    }
};