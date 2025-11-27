// leetcode 438 find all anagrams in a string
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;


map<char, int> fill_char_occurances(string anagram) {
    map<char, int> char_occurances;
    for(const char& letter: anagram) {
        char_occurances[letter]++;
    }
    return char_occurances;
}

bool is_anagram(string text, map<char, int> char_occurances) {
    for(const char letter: text) {
        char_occurances[letter]--;
        if (char_occurances[letter] < 0) {
            return false;
        }
    }
    
    for(const auto [letter, occurances]: char_occurances) {
        if (occurances != 0) {
            return false;
        }
    }
    
    return true;
}

vector<int> find_anagrams(string text, string anagram) {
    vector<int> occurances;
    const map<char, int> char_occurances = fill_char_occurances(anagram);
    
    for(long i_letter=0; i_letter <= (long)text.size()-(long)anagram.size(); i_letter++) {
        if (
            is_anagram(
                text.substr(i_letter, anagram.size()),
                char_occurances
            )
        ) {
            occurances.push_back(i_letter);
        }
    }
    return occurances;
}

class Solution {
public:
    vector<int> findAnagrams(string text, string anagram) {
        return find_anagrams(text, anagram);
    }
};




// int main() {
 
 
//     auto anagrams = find_anagrams("aaaaaaaaaa", "aaaaaaaaaaaaa");
 
//     for(const auto& result_start: anagrams) {
//         cout << result_start << " ";
//     }
 
//     return 0;   
// }

