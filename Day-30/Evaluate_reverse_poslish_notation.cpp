#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    
    int solve(int num1, int num2, char op)
    {
        if (op == '+')
            return num2 + num1;
        if (op == '-')
            return num2 - num1;
        if (op == '*')
            return num2 * num1;
        if (op == '/')
            return num2 / num1;
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> numbers;
        
        for(int i = 0; i < tokens.size(); i++) {
            
            if (tokens[i] != "+" && tokens[i] != "-" && 
                tokens[i] != "*" && tokens[i] != "/") {
                
                numbers.push(stoi(tokens[i]));
            }
            else {
                char op = tokens[i][0];
                
                int num1 = numbers.top(); numbers.pop();
                int num2 = numbers.top(); numbers.pop();
                
                int val = solve(num1, num2, op);
                numbers.push(val);
            }
        }
        
        return numbers.top();
    }
};

