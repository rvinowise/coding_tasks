// leetcode 1 two sum
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;


tuple<int,int> two_sum(vector<int>& numbers, int target) {
    map<int, size_t> lack_to_index; 
    
    for(size_t i_number=0; i_number < numbers.size(); i_number++) {
        auto this_amount = numbers[i_number];
        auto lack = target - this_amount;
        
        auto paired_amount = lack_to_index.find(lack);
        if (paired_amount != lack_to_index.end()) {
            return make_tuple(paired_amount->second, i_number);
        }
        
        lack_to_index[this_amount] = i_number;
    }
    
    throw invalid_argument("no sum found!");
}

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto [start, end] = two_sum(numbers, target);
        return vector<int>{start, end};
    }
};




// int main() {
 
    
//     vector<int> numbers{2,7,11,15};
//     auto [start, end] = two_sum(numbers, 9); // Output: [0,1]
 
//     cout << start << " " << end;
    
 
//     return 0;   
// }

