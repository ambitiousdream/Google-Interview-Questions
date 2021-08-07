'''
/* 
Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.




Input Format:

The only argument given is string A.
Output Format:

Return the length of the longest valid (well-formed) parentheses substring.
Constraints:

1 <= length(A) <= 750000
For Example

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.

*/
'''

Code

int Solution::longestValidParentheses(string A) {
    int n=A.size(),maxi=0;
    stack<int>s;//to store the indexes of '('
    s.push(-1);
    for(int i=0;i<n;i++){
        if(A[i]=='(')
        s.push(i);
        else{
            //if not empty pop the top to form a valid string
            if(!s.empty()){
                s.pop();
            }
            //after popping to find the length, we deduct s.top() from i
            if(!s.empty()){
                maxi=max(maxi,i-s.top());
            }
            //if empty we push as base of the next substring
            else{
                s.push(i);
            }
        }
    }
    return maxi;
}
