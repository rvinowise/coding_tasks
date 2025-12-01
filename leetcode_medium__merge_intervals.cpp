//leetcode 56 merge intervals
/* it fails with TLE at the end, but it seems to work correctly */
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <optional>

using namespace std;


optional<vector<int>> get_overarching_interval_of_partial_overlap(
    vector<int> interval1,    
    vector<int> interval2    
) {
    if (
        interval1[0] <= interval2[0]
        &&
        interval1[1] >= interval2[0]
        
    ) {
        return vector<int>{interval1[0], interval2[1]};
    } else if (
        interval1[0] >= interval2[0]
        &&
        interval1[0] <= interval2[1]    
    ) {
        return vector<int>{interval2[0], interval1[1]};
    }
    
    return nullopt;
}

bool is_interval_encompassing(
    vector<int> outer_interval,    
    vector<int> inner_interval
) {
    return
        outer_interval[0] <= inner_interval[0]
        &&
        outer_interval[1] >= inner_interval[1];
}

optional<vector<int>> get_overarching_interval_of_encompassing(
    vector<int> interval1,    
    vector<int> interval2    
) {
    if (
        is_interval_encompassing(interval1, interval2)
    ) {
        return vector<int>{interval1[0], interval1[1]};
    } else if (
        is_interval_encompassing(interval2, interval1) 
    ) {
        return vector<int>{interval2[0], interval2[1]};
    }
    
    return nullopt;
}


optional<vector<int>> get_overarching_interval(
    vector<int> interval1,    
    vector<int> interval2
) {
    auto encompassing_overlap = get_overarching_interval_of_encompassing(interval1, interval2);
    if (!encompassing_overlap) {
        return get_overarching_interval_of_partial_overlap(interval1, interval2);
    }
    return encompassing_overlap;
    
}

vector<vector<int>> find_unique_intervals(vector<vector<int>>& intervals) {
    
    vector<vector<int>> fused_intervals{intervals};
    
    for(
        auto element: intervals
    ) {
        for(
            size_t i_fixed_interval=0; 
            i_fixed_interval<fused_intervals.size(); 
            i_fixed_interval++
        ) {
            vector<int> fixed_interval{fused_intervals[i_fixed_interval]};
            
            for(
                size_t i_interval=i_fixed_interval+1; 
                i_interval<fused_intervals.size(); 
                i_interval++
            ) {
                auto overarching_interval = get_overarching_interval(
                      fixed_interval,
                      fused_intervals[i_interval]
                );
                if (overarching_interval) {
                    fixed_interval = *overarching_interval;
                    fused_intervals[i_fixed_interval] = *overarching_interval;
                    fused_intervals[i_interval] = *overarching_interval;
                }
            }
        }
    }
    
    set<vector<int>> unique_intervals{fused_intervals.begin(), fused_intervals.end()};
    return vector<vector<int>>{unique_intervals.begin(), unique_intervals.end()};
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return find_unique_intervals(intervals);
    }
};


// int main() {
    
//     vector<vector<int>> intervals{{2,3},{4,6},{5,7},{3,4}};
    
//     vector<vector<int>> unique_intervals = find_unique_intervals(intervals);
    
//     for(auto interval: unique_intervals) {
//         cout << "[" << interval[0] << ", " << interval[1] << "] ";
//     }
//     cout << endl;
    
//     return 0;
// }
