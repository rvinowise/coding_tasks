//yandex task 5. Правильная скобочная последовательность

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

//!yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ',';

bool is_open_brace(char brace) {
    return 
        brace == '('
        ||
        brace == '['
        ||
        brace == '{';
}

bool is_matching_brace(char open_brace, char closing_brace) {
    return 
        open_brace == '(' && closing_brace == ')'
        ||
        open_brace == '[' && closing_brace == ']'
        ||
        open_brace == '{' && closing_brace == '}';
}

bool is_correct_sequence(string braces) {
    stack<char> open_braces;
    for (char brace: braces) {
        if (is_open_brace(brace)) {
            open_braces.push(brace);
        } else {
            if (open_braces.size() == 0) {
                return false;
            }
            char last_open_brace = open_braces.top();
            if (!is_matching_brace(last_open_brace, brace)) {
                return false;
            }
            open_braces.pop();
        }
        
    }
    
    return open_braces.size() == 0;
}

int main() {
    string braces; cin >> braces;
    
    is_correct_sequence(braces) ? 
        cout << "yes"
    :
        cout << "no";
    
    return 0;
}
