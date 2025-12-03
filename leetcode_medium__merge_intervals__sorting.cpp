//leetcode 56. Merge Intervals
/* wrote it myself after learning the algorithm (1 day after reading it) */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void print(const vector<vector<int>>& ints) {
    for(auto in: ints) {
        cout << "[" << in[0] << ", " << in[1] << "] ";
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), intervals.end(),
            [](vector<int> int1, vector<int> int2) {
                return int1[0] < int2[0];
            }
        );
        // cout << "sorted ints:" << endl;
        // print(intervals);
    

        if (intervals.size() == 0) {
            return vector<vector<int>>{};
        }

        vector<vector<int>> merged{intervals.front()};
        

        for(size_t i=1; i< intervals.size(); i++) {
            
            // cout << "i=" << i <<endl;
            
            auto this_interval = intervals[i];
            vector<int>& last_merged = merged.back();
            if (this_interval[0] <= last_merged[1]) {
                last_merged[1] = max(last_merged[1], this_interval[1]);
                //cout << "updating last merged:" << endl;;
                //print(merged);
            } else {
                merged.push_back(this_interval);
                // cout << "adding interval to merged, merged:" << endl;
                //print(merged);
            }
        }
        
        //cout << "returning..." << endl;
        return merged;
    }
};

// int main() {
    
//     vector<vector<int>> intervals {{1,3},{2,6},{8,10},{15,18}};
//     auto results = Solution().merge(intervals);
    
//     cout << "results" << endl;
//     for(auto result: results) {
//         cout << "[" << result[0] << ", " << result[1] << "] ";
//     }
    
//     return 0;
// }
