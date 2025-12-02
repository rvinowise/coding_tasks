//leetcode 424. Longest Repeating Character Replacement
/* after reading the solution, from my memory (after 1 hour) */
#include <iostream>
#include <array>
#include <algorithm>


using namespace std;


int find_longest_substring(string text, int gap_size) {
    int biggest_window_size = 0;
    int start_index = 0;
    int end_index = 0;
    
    array<int, 26> char_amounts{};
    
    while(end_index < text.size()) {
        char_amounts[text[end_index] - 'A']++;
        int window_size = end_index - start_index + 1;
        
        auto commonest_char_iterator =
            max_element(char_amounts.begin(), char_amounts.end());
        int commonest_char_amount = *commonest_char_iterator;
        char commonest_char = distance(
            char_amounts.begin(), 
            commonest_char_iterator
        )+'A';
        // cout 
        //     << " start_index=" << start_index
        //     << " end_index=" << end_index
        //     << " window_size=" << window_size
        //     << " commonest_char=" << commonest_char
        //     << " commonest_char_amount=" << commonest_char_amount
        //     << endl;
            
        if (
            window_size
            > 
            commonest_char_amount + gap_size
        ) {
            char_amounts[text[start_index] - 'A']--;
            start_index++;
        } else {
            biggest_window_size = max(biggest_window_size, window_size);
        }
        
        end_index++;
        
    }
    
    return biggest_window_size;
}


class Solution {
public:
    int characterReplacement(string text, int char_amount) {
        return find_longest_substring(text, char_amount);
    }
};

// int main()
// {
//     string text = "AABABBA";
//     int result = find_longest_substring(text, 1);
    
//     std::cout << "result:" << result;

//     return 0;
// }
