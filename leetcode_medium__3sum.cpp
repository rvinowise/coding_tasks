// leetcode 15 3sum
/* this solution exceeds the time limit at the final tests, but it works */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>

using namespace std;
using namespace std::ranges;

struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        return 0;
    }
};

bool is_unique_pair(vector<vector<int>> results, vector<int> this_pair) {
    if (results.size() == 0) {
        return true;
    }
    if (results.back() != this_pair) {
        // cout 
        //     << "combination is unique: " << this_pair[0] 
        //     << "," << this_pair[1] << endl;
        return true;
    }
    
    // cout
    //     << "combination is not unique: " << this_pair[0] 
    //     << "," << this_pair[1] << endl;
        
    // cout 
    //     << "existing combination: " << results.back()[0]
    //     << "," << results.back()[1] << endl;
    
    
    return false;
}

//template<std::ranges::view View>
//template<typename View>
vector<vector<int>> two_sum(
    vector<int>& numbers, 
    int target
) {
    vector<vector<int>> results;
    
    size_t start = 0;
    size_t end = numbers.size()-1;
    while (start < end) {
        // cout 
        //     << " start=" << start
        //     << " end=" << end
        //     << endl;
        auto this_sum = numbers[start] + numbers[end];
        if (this_sum == target) {
            // cout 
            //     << "found target " << target 
            //     << " number[start]=" << numbers[start]
            //     << " number[end]=" << numbers[end]
            //     << endl;
            vector<int> this_pair{numbers[start], numbers[end]};
            if (
                is_unique_pair(results, this_pair)    
            ) {
                results.push_back(this_pair);
            }
            start++;
        } else {
            if (this_sum < target) {
                start++;
            } else {
                end--;
            }
        }
    }
    
    return results;
}

constexpr int target = 0;


bool is_unique_triplet(vector<vector<int>> triplets, vector<int> triplet) {
    if (triplets.size() == 0) {
        return true;
    }
    if (triplets.back() == triplet) {
        return false;
    }
    return true;
}

vector<vector<int>> three_sum(vector<int>& numbers) {
    
    std::sort(numbers.begin(), numbers.end());
    //set<int> unique_numbers{numbers.begin(), numbers.end()};
    //numbers = vector<int>{unique_numbers.begin(), unique_numbers.end()};
    
    // cout << "sorted numbers:" << endl;
    // for(auto number: numbers) {
    //     cout<< number << " ";
    // }
    // cout << endl;
    
    vector<vector<int>> triplets;
    
    for(size_t i_number=0; i_number< numbers.size()-2; i_number++) {
        auto this_number = numbers[i_number];
        
        // cout
        //     << "set first index as " << i_number 
        //     << " (number=" << this_number << ")" 
        //     << endl;
            
        
        // the copying is actually faster than a range::view
        auto next_numbers = vector<int>(numbers.begin()+i_number+1, numbers.end());
        //auto next_numbers = numbers | std::ranges::views::drop(i_number+1);
        
        auto compliments_sets = two_sum(next_numbers, target-this_number);
        
        for(auto compliments_set: compliments_sets) {
            // cout 
            //     << "compliment set=[" << compliments_set[0] 
            //     << "," << compliments_set[1] << "]" << endl;
            vector<int> triplet{this_number};
            triplet.insert(triplet.end(), compliments_set.begin(), compliments_set.end());
            if (is_unique_triplet(triplets, triplet)) {
                triplets.push_back(triplet);
            }
        }
    }
    
    return triplets;
}

vector<vector<int>> unique_three_sum(vector<int>& numbers) {
    
    vector<vector<int>> triplets = three_sum(numbers);
    
    for(auto& triplet: triplets) {
        std::sort(triplet.begin(), triplet.end());
    }
    
    // cout << "sorted triplets:" <<endl;
    // for(auto triplet: triplets) {
    //     for(auto number: triplet) {
    //         cout << number << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "end sorted triplets" <<endl;
    
    set<vector<int>> unique_triplets{triplets.begin(), triplets.end()};
    return vector<vector<int>>{unique_triplets.begin(), unique_triplets.end()};
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& numbers) {
        return unique_three_sum(numbers);
    }
};




int main() {
 
    
    vector<int> numbers{
        2,-8,8,6,-14,-12,11,-10,13,14,7,3,10,-13,3,-15,7,3,-11,-8,4,5,9,11,7,1,3,13,14,-13,3,-6,-6,-12,-15,-12,-9,3,-15,-11,-6,-1,0,11,2,-12,3,-6,6,0,-6,-12,-10,-12,6,5,-4,-5,-5,-4,-11,13,5,-2,-13,-3,-7,-15,8,-15,12,-13,0,-3,6,9,-8,-6,10,5,9,-11,0,7,-15,-8,-3,-4,-6,7,7,-2,-2,-11,3,0,-6,12,0,-13,4,-3,11,-11,1,2,13,8,4,9,-1,-2,5,14,12,5,13,-6,-13,-8,9,1,5,-8,-2,-6,-1
    };
    
    vector<vector<int>> groups = three_sum(numbers);
 
    for(auto group: groups) {
        for(auto number: group) {
            cout << number << " ";
        }
        cout << endl;
    }
    
 
    return 0;   
}

