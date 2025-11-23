//yandex task 10. Высота дерева

/* 
input:
7,3,2,1,9,5,4,6,8,0
output:
4
*/

#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>

using namespace std;

//!yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ',';

using vertex_id = int;

struct Node {
    int value;
    unique_ptr<Node> smaller;  
    unique_ptr<Node> greater;
    Node(int _value): value(_value) {};
    int insert_number(int in_value);
    int insert_number_recursive(int in_value, int current_depth);
};

int Node::insert_number_recursive(int in_value, int current_depth) {
    current_depth++;
    //cout << "insert number " << in_value << " depth= " << current_depth << endl; 
    if (value != in_value) {
        if (value < in_value) {
            if (smaller != nullptr) {
                return smaller->insert_number_recursive(in_value, current_depth);
            } else {
                smaller = make_unique<Node>(in_value);
                return current_depth;
            }
        } else {
            if (greater != nullptr) {
                return greater->insert_number_recursive(in_value, current_depth);
            } else {
                greater = make_unique<Node>(in_value);
                return current_depth;
            }
        }
    }
    return current_depth;
}

int Node::insert_number(int in_value) {
    return insert_number_recursive(in_value, 1);
}

int input_tree() {
    string input; cin >> input;
    stringstream ss(input);
    string str_last_number;
    
    unique_ptr<Node> root;
    int depth = 0, deepest_depth = 0;
    
    int last_number;
    getline(ss, str_last_number, delimiter);
    last_number = stoi(str_last_number);
    
    while (last_number != 0) {
        if (root==nullptr) {
            root = make_unique<Node>(Node(last_number));
            deepest_depth = 1;
        } else {
            depth = root->insert_number(last_number);
            deepest_depth = max(deepest_depth, depth);
        }
        getline(ss, str_last_number, delimiter);
        last_number = stoi(str_last_number);
    }
    return deepest_depth;
}

int main() {
    auto depth = input_tree();
    
    cout << depth << endl;
    
    return 0;
}
