/* leletcode medium 134 Gas Station  
bruteforce solution with TLE
*/
class Solution {
    int can_drive_straight(
        const vector<int>& gas, 
        const vector<int>& cost,
        size_t start, size_t end,
        int initial_gas
    ) {
        int current_gas{initial_gas};
        for(size_t i_station=start; i_station < end; ++i_station) {
            current_gas += gas[i_station];
            if(current_gas < cost[i_station]) {
                return current_gas-cost[i_station];
            }
            current_gas -= cost[i_station];
        }
        return current_gas;
    }
    
    bool can_drive_circle_from_station(
        const vector<int>& gas, 
        const vector<int>& cost,
        size_t start
    ) {
          
        int gas_left = can_drive_straight(gas, cost, start, gas.size(), 0);
        if (gas_left >= 0) {    
            return can_drive_straight(gas, cost, 0, start+1, gas_left) >= 0;
        }
        return false;
    }


public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(size_t start=0; start < gas.size(); start++) {
            if (can_drive_circle_from_station(gas, cost, start)) {
                return start;
            }
        }      
        return -1;
    }
};
