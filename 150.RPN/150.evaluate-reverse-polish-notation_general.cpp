/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (29.90%)
 * Total Accepted:    134K
 * Total Submissions: 445.5K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> s;
        int length = tokens.size();
		for(int i = 0;i < length;i++){
			if(tokens[i][0] >= 48 || tokens[i].length() > 1){
				int num = stoi(tokens[i]);
				s.push(num);
			}
			else {
				char operatorr = (int)tokens[i][0];
				int operand1 = s.top();
				s.pop();
				int operand2 = s.top();
				s.pop();
				//cout<<"op2 = "<<operand2<<" op1 = " <<operand1<<"\n";
				switch(operatorr){
					case '+':
					{
						s.push(operand2 + operand1);
						break;
					}
					case '-':
					{
						s.push(operand2 - operand1);
						break;
					}
					case '*':
					{
						s.push(operand2 * operand1);
						break;
					}
					case '/':
					{
						s.push(operand2 / operand1);
						break;
					}
				}
			}
		}
		return s.top();
    }
};
