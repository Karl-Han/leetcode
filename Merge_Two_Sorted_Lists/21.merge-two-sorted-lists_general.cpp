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
		ListNode *L;
		ListNode *head;
		if(l1 == NULL){
			head = l2;
			return head;
		}
		if(l2 == NULL){
			head = l1;
			return head;
		}
		if(l1->val < l2->val){
			ListNode *newNode = new ListNode(l1->val);
			L = newNode;
			l1 = l1->next;
		}
		else{
			ListNode *newNode = new ListNode(l2->val);
			L = newNode;
			l2 = l2->next;
		}
		head = L;
        while(l1 != NULL){
			if(l2 == NULL){
				L->next = l1;
				break;
			}
			if(l1->val < l2->val){
				ListNode *newNode = new ListNode(l1->val);
				L->next = newNode;
				L = L->next;
				l1 = l1->next;
			}
			else{
				ListNode *newNode = new ListNode(l2->val);
				L->next = newNode;
				L = L->next;
				l2 = l2->next;
			}
		}
		if(l2 != NULL && l1 == NULL)
			L->next = l2;
		return head;
    }
};
