/* 
Write a function that returns if a string of paranthesis are matched. 
You are required to use the STL stack datastructure in your code for O(n) time complexity.
See 5.17 in the book for problem description and a stack based algorithm. 
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std; 
  
// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) { 
// Your code here
	stack<char> matching; 
	// Loop through each character in the string.
	for (int i = 0; i < expr.size(); i++) {
		if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
			// Push into the stack.
			matching.push(expr[i]);
		}
		else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
			if (matching.empty()) {
				return false;
			}
			switch (matching.top()) {   // Matching the type of char. If doesn't matched, false. 
				case '(':
					if (expr[i] == '}' || expr[i] == ']') {
						return false;
					}
					break;
				case '{':
					if (expr[i] == ')' || expr[i] == ']') {
						return false;
					}
					break;
				case '[':
					if (expr[i] == ')' || expr[i] == '}') {
						return false;
					}
					break;
			}
			matching.pop();
		}
	}
	if (matching.empty()) {
		return true;
	}
	else {
		return false;
	}
} 
  
// Test - DO NOT MODIFY
int main() 
{ 
    vector<string> parans = {"{()}[]", "[[", "))", "{[()]}", "({[])}"}; 
  	
	for(auto expr : parans) {
    	if (areParanthesisBalanced(expr)) 
        	cout << "Balanced" << endl; 
    	else
        	cout << "Not Balanced" << endl;
	} 
    return 0; 
}
