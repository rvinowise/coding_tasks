//leetcode 424. Longest Repeating Character Replacement
/* bruteforce solution, it fails with TLE in the middle of tests, but it works */
#include <iostream>
#include <thread>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

int streak_from_index_and_char(
    const string& text, 
    int start_index, 
    char symbol,
    int gap_size
) {
    int streak = 0;
    int left_changes = gap_size;
    
    // cout 
    //     << " streak_from_index_and_char"
    //     << " starting from text[" << start_index
    //     << "]=" << text[start_index]
    //     << " symbol=" << symbol
    //     << endl;
    
    for(size_t i_char = start_index; i_char< text.size(); i_char++) {
        char current_char = text[i_char];
        if (current_char != symbol) {
            if (--left_changes < 0) {
                // cout
                //     << "no substitutions left, streak=" << streak
                //     <<endl;
                return streak;
            }
        }
        streak++;
    }
    // cout
    //     << "reached the end, streak=" << streak
    //     <<endl;
        
    return streak;
}

int streak_from_index(const string& text, int start_index, int gap_size) {
    set<char> symbols{text.begin(), text.end()};
    int greatest_streak = 0;
    
    // cout
    //     << " streak_from_index" 
    //     << " starting from text[" << start_index 
    //     << "]=" << text[start_index]
    //     << endl;
    
    for(char symbol: symbols) {
        greatest_streak = max(
            greatest_streak,
            streak_from_index_and_char(
                text,
                start_index,
                symbol,
                gap_size
            )
        );
    }
    
    return greatest_streak;
}

int find_longest_substring(string text, int gap_size) {
    int greatest_streak = 0;
    for(size_t i_start=0; i_start< text.size(); i_start++) {
        int this_streak = streak_from_index(text, i_start, gap_size);
        greatest_streak = max(this_streak, greatest_streak);
    }
    return greatest_streak;
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
