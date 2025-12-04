/* leetcode 11. Container With Most Water 
did it several days after reading the solution. recalled it vaguely. 
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        size_t left_wall{0};      
        size_t right_wall{heights.size()-1};
        int max_area{0};
        while(left_wall < right_wall) {
            // cout
            //     << " left_wall=" << left_wall
            //     << " right_wall=" << right_wall
            //     << endl;

            int this_width = right_wall - left_wall;
            int this_height = min(heights[left_wall], heights[right_wall]);
            int this_area = this_width * this_height;
            max_area = max(max_area, this_area);
            if (heights[left_wall] < heights[right_wall]) {
                left_wall++;
            } else {
                right_wall--;
            }
        }
        return max_area;

    }
};
