// leetcode 567 permutation in string
/* 
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;


map<char,int> fill_letter_amounts(string permutation) {
    map<char,int> letter_amounts;
    for(char letter: permutation) {
        letter_amounts[letter]++;
    }
    return letter_amounts;
}

bool is_permutation(string text, map<char,int> letter_amounts) {
    //cout << "is_permutation(" << text << "..)" << endl;
    for(char letter: text) {
        if (letter_amounts[letter]-- < 0) {
            return false;
        }
    }
    for(auto [letter, amount]: letter_amounts) {
        if (amount != 0) {
            return false;
        }
    }
    return true;
}

bool is_containing_permuitation(string text, string permutation) {
    map<char,int> letter_amounts = fill_letter_amounts(permutation);
    for(long i_letter=0;i_letter <= (long)text.size()-(long)permutation.size();i_letter++) {
        if (
            is_permutation(
                text.substr(i_letter, permutation.size()),
                letter_amounts
            )
        ) {
            return true;
        }
    }
    return false;
}


class Solution {
public:
    bool checkInclusion(string permutation, string text) {
        return is_containing_permuitation(text, permutation);
    }
};




// int main() {
 
 
//     auto is_containing = is_containing_permuitation("a", "ab");
 
//     cout << boolalpha << is_containing << " ";
    
 
//     return 0;   
// }

