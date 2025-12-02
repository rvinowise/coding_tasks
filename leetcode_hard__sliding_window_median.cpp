//leetcode 480 sliding window median
/* it fails at the very end because of TLE. it's more or less bruteforce */
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <optional>

using namespace std;

double get_median_from_window(
    const vector<int>& numbers, 
    size_t start, 
    size_t window_size
) {
    vector<int> span{numbers.begin()+start, numbers.begin()+start+window_size};
    sort(span.begin(), span.end());
    double median;
    if (span.size() % 2 == 0) {
        median = (
            (double)span[span.size()/2 - 1] 
            + 
            (double)span[span.size()/2]
        ) / 2;
    } else {
        median = span[
            floor(span.size()/2)
        ];
    }
    return median;
}

vector<double> median_sliding_window(vector<int>& numbers, size_t window_size) {
    vector<double> medians;
    
    for(size_t i_start=0; i_start <= numbers.size()-window_size; i_start++) {
        double current_median = get_median_from_window(numbers, i_start, window_size); 
        medians.push_back(current_median);
    }
    
    return medians;
}

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& numbers, size_t window_size) {
        return median_sliding_window(numbers, window_size);
    }
};

// int main() {
    
//     vector<int> numbers{1,4,2,3};
    
//     auto medians = median_sliding_window(numbers, 4);
    
//     cout << "final result:" << endl;
//     for(auto median: medians) {
//         cout << median << " ";
//     }
    
//     return 0;
// }
