/* 
leetcode medium 150. Evaluate Reverse Polish Notation
i wrote the code after reading the algorithm on wikipedia
*/

#include <string>

class Solution {
    bool is_operator(const string& token) {
        return 
            token == "+" ||
            token == "-" ||
            token == "*" ||
            token == "/";
    }

    void perform_operation(
        stack<string>& accumulated_tokens, 
        const string& operation
    ) {
        int operand_r = stoi(accumulated_tokens.top());
        accumulated_tokens.pop();
        int operand_l = stoi(accumulated_tokens.top());
        accumulated_tokens.pop();
        
        int result{0};
        if (operation == "+") {
            result = operand_l + operand_r;
        } else if (operation == "-") {
            result = operand_l - operand_r;
        } else if (operation == "*") {
            result = operand_l * operand_r;
        } else if (operation == "/") {
            result = operand_l / operand_r;
        } else {
            throw invalid_argument("unknown operator");
        }
        accumulated_tokens.push(to_string(result));
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> accumulated_tokens;

        for(size_t i_token=0; i_token<tokens.size(); i_token++) {
            string current_token = tokens[i_token];
            if (is_operator(current_token)) {
                perform_operation(accumulated_tokens, current_token);
            } else {
                accumulated_tokens.push(current_token);
            }
        }

        return stoi(accumulated_tokens.top());
    }
};
