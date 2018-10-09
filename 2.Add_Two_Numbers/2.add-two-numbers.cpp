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
        ListNode *L = (ListNode*)malloc(sizeof(ListNode));
		ListNode *head = L;
		int num = 0;
		int exp = 0;
		int adder = 0;
		do{
			if(l1 == NULL){
				while(l2){
					num = l2->val + adder;
					ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
					if(num > 9){
						num -= 10;
						adder = 1;
					}
					newNode->val = num;
					L->next = newNode;
					l2 = l2->next;
					return head->next;
				}
			}
			if(l2 == NULL){
				while(l1){
					num = l1->val + adder;
					ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
					if(num > 9){
						num -= 10;
						adder = 1;
					}
					newNode->val = num;
					L->next = newNode;
					L = L->next;
					l1 = l1->next;
				}
				return head->next;;
			}
			
		}while(1);
    }
};
