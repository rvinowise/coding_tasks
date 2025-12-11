/* 
task #2 from here: https://habr.com/ru/articles/550088/
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<map>
#include<algorithm>
#include<ranges>
#include<sstream>

using namespace std;

string group_symbols(
    string text
) {
    vector<tuple<char, size_t>> grouped_chars;
    char prev_symbol{text.front()};
    size_t prev_amount{1};
    for(size_t i_sym=1; i_sym<text.size(); ++i_sym) {
        char current_symbol = text[i_sym];
        if (current_symbol == prev_symbol) {
            ++prev_amount;
        } else {
            grouped_chars.push_back(
                make_tuple(prev_symbol, prev_amount)
            );
            prev_amount=1;
        }
        prev_symbol = current_symbol;
    }
    grouped_chars.push_back(
        make_tuple(prev_symbol, prev_amount)
    );
    
    stringstream ss;
    for(auto [symbol, amount]: grouped_chars) {
        ss << symbol << amount;
    }
    return ss.str();
}

int main(int argc, char** args) {
    string input{"AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB"};
    
    auto result = group_symbols(input);
    
    cout << "result:" << result;
    // for(auto num: result) {
    //     cout << " " << num;
    // }
    
    //size_t longest = longest_part(numbers, 1);
    
    //cout << "result: " << weasel.weight << " " << weasel2.weight << endl;


    
    return 0;
}
