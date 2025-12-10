/* leetcode medium 134. Gas Station 
i recreated the solution right after seeing it.
*/

#include <numeric> // for accumulate

using namespace std;

class Solution {
    tuple<int, size_t> reach_station(
        const vector<int>& gas, 
        const vector<int>& cost,
        size_t start, size_t end,
        int initial_gas
    ) {
        int current_gas{initial_gas};
        for(size_t i_station=start; i_station < end; ++i_station) {
            current_gas += gas[i_station];
            if(current_gas < cost[i_station]) {
                return make_tuple(current_gas, i_station);
            }
            current_gas -= cost[i_station];
        }
        return make_tuple(current_gas, end-1);
    }
    
    tuple<bool, size_t> can_drive_circle_from_station(
        const vector<int>& gas, 
        const vector<int>& cost,
        size_t start
    ) {
        auto [gas_left, reached_station] = reach_station(gas, cost, start, gas.size(), 0);
        if (reached_station == gas.size()-1) {    
            auto [_, reached_station] = reach_station(gas, cost, 0, start+1, gas_left);
            if (reached_station == start) {
                return make_tuple(true, reached_station);
            }
        }
        return make_tuple(false, reached_station);
    }


public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (
            accumulate(gas.begin(), gas.end(), 0) < 
            accumulate(cost.begin(), cost.end(), 0)
         ) {
            return -1;
        }

        size_t start{0};
        while(start < gas.size()) {
            auto [is_success, reached_station] = 
                can_drive_circle_from_station(gas, cost, start);
            if (is_success) {
                return start;
            } else {
                start = reached_station+1;
            }
        }      
        return -1;
    }
};
