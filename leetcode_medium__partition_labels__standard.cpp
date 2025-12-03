/*  leetcode medium 763. Partition Labels
i wrote it myself after remembering the algorithm (1-2 days after)
*/

#include <map>

class Solution {
public:
    vector<int> partitionLabels(string text) {
        map<char, int> char_reach;
        //array<int, 26> char_reach;
        for(int i=0; i< text.size(); i++) {
            char_reach[text[i]] = i;
            //char_reach[text[i]-'a'] = i;
        }

        // cout << "char reach:" << endl;
        // for(auto [symbol, reach]: char_reach) {
        //     cout << " " << symbol << "=" << reach;
        // }
        // cout << endl;

        vector<int> partition_sizes;
        int current_reach{0};
        int previous_reach{0};

        for(size_t i_symbol=0; i_symbol < text.size(); i_symbol++) {
            char current_symbol = text[i_symbol];
            current_reach = max(current_reach, char_reach[current_symbol]);
            if (current_reach == i_symbol) {
                int partition_size = current_reach - previous_reach + 1;
                partition_sizes.push_back(partition_size);
                previous_reach = current_reach + 1;
            }
        }

        return partition_sizes;
    }
};
