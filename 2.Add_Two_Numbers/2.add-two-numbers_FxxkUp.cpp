/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.19%)
 * Total Accepted:    606K
 * Total Submissions: 2.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int adder = 0;
		int sum = 0;
		ListNode *L = (ListNode*)malloc(sizeof(ListNode));
		ListNode *head = L;
        do{
			if(l1 == NULL){
				if(adder)
					if(l2){
						l2->val += 1;
						if(l2->val > 9){
							l2->val -=10;
							if(l2->next)
								l2->next->val++;
							else {
								l2->next = (ListNode*)malloc(sizeof(ListNode));
								l2->next->val = 1;
							}
						}
					}
					else {
						l2 = (ListNode*)malloc(sizeof(ListNode));
						l2->val = 1;
					}
				L->next = l2;
				return head->next;
			}
			if(l2 == NULL){
				if(adder)
					if(l1){
						l1->val += 1;
						if(l1->val > 9){
							l1->val -=10;
							l1 = l1->next;
							if(l1->next)
								l1->next->val++;
							else {
								l1->next = (ListNode*)malloc(sizeof(ListNode));
								l1->next->val = 1;
							}
						}
					}
					else {
						l1 = (ListNode*)malloc(sizeof(ListNode));
						l1->val = 1;
					}
				L->next = l1;
				return head->next;
			}
			sum = l1->val + l2->val + adder;
			adder = 0;
			if(sum > 9){
				adder = 1;
				sum -=10;
			}
			L->next = (ListNode*)malloc(sizeof(ListNode));
			L->next->val = sum;
			L = L->next;
			l2 = l2->next;
			l1 = l1->next;
		}while(1);
    }
};
