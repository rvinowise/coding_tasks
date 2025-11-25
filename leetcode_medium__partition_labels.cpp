//leetcode 763 Partition Labels
#include <sstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int split_at_position(const string& text, int position) {
    string chunk = text.substr(0, position);
    set<char> split_chars{begin(chunk), end(chunk)};

    string rest_text = text.substr(position);
    for(const char& distant_symbol: rest_text) {
        if (split_chars.contains(distant_symbol)) {
            return 0;
        }
    }
    cout << "chunk is split: " << chunk <<endl;
    return split_chars.size();
}

int separate_one_chunk(string text) {
    for (size_t i_char =1; i_char<text.size(); i_char++) {
        int chars_amount = split_at_position(text, i_char);
        if (chars_amount > 0) {
            return i_char;
        }
    }
    return 0;
}

vector<int> separate_all_chunks(string text) {
    vector<int> chunk_sizes;

    int last_chunk_size = separate_one_chunk(text);
    while (last_chunk_size > 0) {
        // cout 
        //     << "last_chunk_size=" << last_chunk_size
        //     << " text=" << text
        //     << endl;
        chunk_sizes.push_back(last_chunk_size);
        text.erase(0, last_chunk_size);
        // cout 
        //     << "text after erasing= " << text
        //     << endl;
        last_chunk_size = separate_one_chunk(text);
    }
    chunk_sizes.push_back(text.size());

    return chunk_sizes;
}

class Solution {
public:
    vector<int> partitionLabels(string text) {
        return separate_all_chunks(text);
    }
};

// int main() {
 
//     string text = "ababcbacadefegdehijhklij";
//     auto result = separate_all_chunks(text);
    
//     for (const auto& chunk: result) {
//         cout << chunk << " ";
//     }
//     return 0;   
// }
