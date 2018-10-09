/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (43.33%)
 * Total Accepted:    416.5K
 * Total Submissions: 961.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *L = new ListNode(0);
		ListNode *head = L;
		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				L->next = l1;
				l1 = l1->next;
				L = L->next;
			}
			else {
				L->next = l2;
				l2 = l2->next;
				L = L->next;
			}
		}
		if(l2 != NULL)
			L->next = l2;
		else if(l1 != NULL)
			L->next = l1;
		return head->next;
    }
};

