//leetcode medium 424. Longest Repeating Character Replacement
/* */
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

int commonest_char_amount(const array<int, 26>& amounts) {
    int max_amount = 0;

    for(auto amount: amounts) {
        max_amount = std::max(max_amount, amount);
    }

    return max_amount;
}

string window_as_string(const multiset<char>& chars) {
    stringstream ss;

    for(auto symbol: chars) {
        ss << " " << symbol;
    }

    return ss.str();
}

class Solution {
public:
    int characterReplacement(string text, int gap_size) {
        size_t start=0;
        size_t end=0;
        size_t max_streak = 0;
        while(end < text.size()) {

            // cout
            //     << " iteration start; "
            //     << " start=" << start
            //     << " end=" << end
            //     << endl;

            char new_char = text[end];
            size_t window_size = end - start + 1;
            char_window[new_char-'A']++;

            // cout 
            //     << "inserted " << new_char << endl
            //     << "window:" << window_as_string(char_window)
            //     <<endl;
            
            auto commonest_amount = commonest_char_amount(char_window);
            if (
                window_size > commonest_amount + gap_size
            ) {
                char_window[text[start]-'A']--;
                start++;
                // cout
                //     << "start moved to " << start << endl
                //     << "removing " << text[start] << " from window"
                //     << endl;
            } else {
                max_streak = max(max_streak, window_size);
                // cout
                //     << "max_streak= " << max_streak
                //     << endl;
            }
            end++;

            // cout
            //     << " iteration end;" << endl
            //     << " start=" << start
            //     << " end=" << end
            //     << endl << endl;
        }

        return max_streak;
    }
private:
    array<int,26> char_window;
};
