/* leetcode easy 977. Squares of a Sorted Array 
ideally, it should return a deque (because of the addition to the beginning).
i remember the seen solution.
*/

#include <cmath>
#include <list>
#include <deque>

class Solution {
private:
    vector<int> sorted_squares_reverse_vector(vector<int>& nums) {
        vector<int> result;

        size_t start{0};
        size_t end{nums.size()-1};

        while(start <= end) {
            int start_sqr = pow(nums[start], 2);
            int end_sqr = pow(nums[end], 2);

            if (start_sqr < end_sqr) {
                end--;
                result.push_back(end_sqr);
            } else {
                start++;
                result.push_back(start_sqr);
            }
        }
        reverse(result.begin(), result.end());

        return result;
    }

    vector<int> sorted_squares_list(vector<int>& nums) {
        list<int> result;

        size_t start{0};
        size_t end{nums.size()-1};

        while(start <= end) {
            int start_sqr = pow(nums[start], 2);
            int end_sqr = pow(nums[end], 2);

            if (start_sqr < end_sqr) {
                end--;
                result.push_front(end_sqr);
            } else {
                start++;
                result.push_front(start_sqr);
            }
        }
        //reverse(result.begin(), result.end());
        vector<int> result_vector{result.begin(), result.end()};

        return result_vector;
    }

    vector<int> sorted_squares_deque(vector<int>& nums) {
        deque<int> result;

        size_t start{0};
        size_t end{nums.size()-1};

        while(start <= end) {
            int start_sqr = pow(nums[start], 2);
            int end_sqr = pow(nums[end], 2);

            if (start_sqr < end_sqr) {
                end--;
                result.push_front(end_sqr);
            } else {
                start++;
                result.push_front(start_sqr);
            }
        }
        //reverse(result.begin(), result.end());
        vector<int> result_vector{result.begin(), result.end()};

        return result_vector;
    }

public:
    vector<int> sortedSquares(vector<int>& nums) {
        return sorted_squares_deque(nums);
    }
};
