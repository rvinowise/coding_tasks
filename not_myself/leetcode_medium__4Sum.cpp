// leetcode 18 4sum
/* practically, it's kSum (a universal implementation) 
i wrote it from memory, after reading the explanation of the algorithm
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges>
#include <optional>

using namespace std;
using namespace std::ranges;


void skip_same_numbers(
    const vector<int>& numbers,
    optional<int> prev_start_number,    
    optional<int> prev_end_number,    
    int &start,    
    int &end
) {
    if (prev_start_number == numbers[start]) {
        start++;
    }
    if (prev_end_number == numbers[end]) {
        end--;
    }
}

vector<vector<int>> two_sum(vector<int> numbers, long target) {
    int start = 0;
    int end = numbers.size()-1;
    
    vector<vector<int>> pairs;
    
    optional<int> prev_start_number;
    optional<int> prev_end_number;
    
    while(start < end) {
        if (prev_start_number == numbers[start]) {
            start++;
            // cout 
            //     << "prev_start_number has the same value " << *prev_start_number 
            //     << ", skip" << endl;
            continue;
        }
        if (prev_end_number == numbers[end]) {
            end--;
            // cout 
            //     << "prev_end_number has the same value " << *prev_end_number 
            //     << ", skip" << endl;
            continue;
        }
        
        // cout 
        //     << "two_sum"
        //     << " start #" << start 
        //     << " = " << numbers[start]
        //     << " end #" << end
        //     << " = " << numbers[end]
        //     << endl;
        long current_sum = numbers[start] + numbers[end];
        if (current_sum == target) {
            pairs.push_back(
                vector<int>{numbers[start], numbers[end]}
            );
            prev_start_number = numbers[start];
            prev_end_number = numbers[end];
            start++;
            end--;
        } else if (current_sum < target) {
            prev_start_number = numbers[start];
            start++;
        } else {
            prev_end_number = numbers[end];
            end--;
        }
        
    }
    
    return pairs;
}

vector<vector<int>> k_sum_recursive(
    vector<int> numbers, 
    long target, 
    int numbers_amount_left
) {

    if (numbers_amount_left == 2) {
        return two_sum(numbers, target);
    }
    
    vector<vector<int>> results;
    optional<int> prev_number;
    
    for(long i_number=0; i_number < (long)numbers.size()-numbers_amount_left+1; i_number++) {

        int fixed_number = numbers[i_number];
        
        if (prev_number.has_value() &&  *prev_number == fixed_number) {
            // cout 
            //     << "prev_number has the same value " << *prev_number 
            //     << ", skip" << endl;
            continue;
        } 
        prev_number = fixed_number;
        
        long lacking_sum = target - fixed_number;
        vector<int> next_numbers = vector<int>{numbers.begin()+i_number+1, numbers.end()};
        
        // cout 
        //     << " numbers_amount_left=" << numbers_amount_left
        //     << " i_number #" << i_number
        //     << " = " << fixed_number
        //     << " target=" << target
        //     <<endl;
        
        vector<vector<int>> complement_sets = k_sum_recursive(
            next_numbers, 
            lacking_sum, 
            numbers_amount_left-1
        );
            
        
        for(auto complements_set: complement_sets) {
            // cout 
            //     << "found complements: ";
            // for(auto complement: complements_set) {
            //     cout << complement << " ";
            // }
            // cout << endl;
            
            vector<int> this_result{fixed_number};
            this_result.insert(
                this_result.end(), 
                complements_set.begin(), 
                complements_set.end()
            );
            results.push_back(
                this_result
            ); 
        }
    }
    
    return results;
}

vector<vector<int>> k_sum(vector<int>& numbers, long target, int numbers_amount) {
    std::sort(numbers.begin(), numbers.end());
    
    // cout << "sorted nubers: ";
    // for(auto number: numbers) {
    //     cout << number << " ";
    // }
    // cout << endl;
    
    return k_sum_recursive(numbers, target, numbers_amount);
    
    //return vector<vector<int>>{};
}


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& numbers, int target) {
        return k_sum(numbers, target, 4);
    }
};

// int main() {
 
    
//     vector<int> numbers{
//         1000000000,1000000000,1000000000,1000000000
//     };
    
//     vector<vector<int>> groups = k_sum(numbers, -294967296, 4);
 
//     for(auto group: groups) {
//         for(auto number: group) {
//             cout << number << " ";
//         }
//         cout << endl;
//     }
    
 
//     return 0;   
// }

