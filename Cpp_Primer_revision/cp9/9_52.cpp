#include <string>
#include <stack>
#include <iostream>

int main() {
	std::string parenthesis;
	std::string open("({[");
	std::string close("]})");
	std::stack<std::string> stk;
	std::stack<std::string> soFar;
	
	while(cin >> parenthesis) 
		stk.push(parenthesis);
	
	while (!stk.empty()) {
		stk.top
	} 
}