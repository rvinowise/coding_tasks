//leetcode 239 sliding window maximum
/* solving it after solving sliding-window-median (from tutorials).
in both tasks i used the simple approach with a multiset instead of priority_queue (heap). it's slower, but still leverages the algorithm*/

#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void print_elements(string name, const multiset<int>& elements) {
    cout << name << ":";
    for(auto element: elements) {
        cout << " " << element;
    }
    cout << endl;
}

class Max_window {
public:
    Max_window(size_t _size): size(_size) {};

    int max() {
        return *elements.rbegin();
    }
    
    void add(int value) {
        // cout 
        //     << "add(" << value << ")" << endl;
        elements.insert(value);
    }
    
    void remove(int value) {
        auto iter = elements.find(value);
        if(iter==elements.end()) {
            throw invalid_argument("removed value must be in the window!");
        }
        elements.erase(iter);
    }

private:
    size_t size;
    multiset<int> elements;
};


vector<int> max_sliding_window(const vector<int>& numbers, size_t window_size) {
    Max_window window(window_size);
    
    for(auto i=0; i<window_size; i++) {
        // cout
        //     << "i=" << i
        //     <<endl;
        window.add(numbers[i]);        
    }
    
    vector<int> results{window.max()};
    
    for(auto i_start=1; i_start <= numbers.size() - window_size; i_start++) {
        // cout
        //     << "i_start= " << i_start
        //     <<endl;
        
        window.add(numbers[i_start+window_size-1]);
        window.remove(numbers[i_start-1]);
        results.push_back(window.max());
    }
    return results;
}



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& numbers, size_t window_size) {
        return max_sliding_window(numbers, window_size);
    }
};

// int main() {
    
//     vector<int> numbers{1,3,-1,-3,5,3,6,7};
    
//     auto results = max_sliding_window(numbers, 3);
    
//     cout << "final result:" << endl;
//     for(auto result: results) {
//         cout << result << " ";
//     }
    
//     return 0;
// }
