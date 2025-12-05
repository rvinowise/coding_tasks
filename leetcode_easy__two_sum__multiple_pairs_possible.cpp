/* leetcode easy 1 Two Sum
it's a solution which works with many possible pairs, which give the target sum
*/
#include<set>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        map<size_t, vector<int>> number_indices;
        vector<vector<int>> results;

        for(size_t i=0; i< nums.size(); i++) {
            number_indices[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());

        size_t left{0};
        size_t right{nums.size()-1};

        while(left < right) {

            cout
                << "nums[" <<left << "]=" << nums[left]
                << " nums[" <<right << "]=" << nums[right]
                <<endl;

            int this_sum = nums[left] + nums[right];
            if (this_sum < target) {
                left++;
            } else if (this_sum > target) {
                right--;
            } else {
                cout << "found target " << target << endl;
                vector<int> left_indices = number_indices[nums[left]];
                vector<int> right_indices = number_indices[nums[right]];

                for(auto i_left: left_indices) {
                    for(auto i_right: right_indices) {
                        if (i_left != i_right) {
                            cout << "adding result: " << i_left << " " << i_right << endl;
                            results.push_back({i_left, i_right});
                        }
                    }
                }
                left++;
            }
        }

        cout
            << "number indices:" << endl;
        for(auto [number, indices]: number_indices) {
            cout << "number " << number << ":";
            for(auto i: indices) {
                cout << " " << i;
            }
            cout << endl;
        }

        return results;
    }
};

int main(int argc, char** args) {
    
    vector<int> nums{2,7,8,11,15,1};
    int target = 9;
    
    auto results = Solution().twoSum(nums, target);
    
    cout << "results:" << endl;
    for(auto result: results) {
        cout << result[0] << " " << result[1] << endl;
    }
    
    return 0;
}
