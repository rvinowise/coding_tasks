// leetcode 560 subarray sum equals k
/* copied the editorial best solution */
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;


int find_needed_sums_amount(vector<int>& numbers, int needed_sum) {
    int needed_sums_amount = 0;
    map<int, int> sum_to_amount{{0,1}};
    int sum_so_far = 0;
    for(size_t i_number=0; i_number<numbers.size(); i_number++) {
        // cout
        //     << "iteration begin"
        //     << " i_number=" << i_number
        //     << " number=" << numbers[i_number]
        //     << " sum_so_far=" << sum_so_far
        //     << " sum_to_amount[" << sum_so_far << "]=" << sum_to_amount[sum_so_far]
        //     << endl;
        sum_so_far += numbers[i_number];
        auto difference = sum_so_far - needed_sum;
        needed_sums_amount += sum_to_amount[difference];
        if (sum_to_amount[difference] > 0) {
            // cout 
            //     << "found " << sum_to_amount[difference] 
            //     << " occurences of sum " << needed_sum 
            //     << ", needed_sums_amount=" << needed_sums_amount << "!" << endl;
         }
        sum_to_amount[sum_so_far]++;
        // cout
        //     << "iteration end"
        //     << " sum_so_far=" << sum_so_far
        //     << " sum_to_amount[" << sum_so_far << "]=" << sum_to_amount[sum_so_far]
        //     << endl << endl;
    }
    
    return needed_sums_amount;
}


class Solution {
public:
    int subarraySum(vector<int>& numbers, int needed_sum) {
        return find_needed_sums_amount(numbers, needed_sum);
    }
};




// int main() {
 
//     //vector<int> input = {-1,-1,1};
//     vector<int> input = {2,3,4,7,-2,2,1,4,2};
 
//     auto result = find_needed_sums_amount(input, 7);
 
//     cout << result;
 
//     return 0;   
// }

