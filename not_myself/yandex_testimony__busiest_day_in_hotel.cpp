/* 
yandex testimony task #5 from here: https://habr.com/ru/articles/550088/
i'm not sure if it calculates it correctly, but it seems so
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<map>
#include<algorithm>
#include<ranges>
#include<sstream>

using namespace std;

int find_busiest_day(vector<tuple<int,int>>& guest_dates) {
    map<int, int> day_events;
    for(auto [check_in_day, check_out_day]: guest_dates) {
        day_events[check_in_day]++;
        day_events[check_out_day]--;
    }
    int occupancy_change{0};
    int max_occupancy{0};
    for(auto [day, current_occupancy_change]: day_events) {
        occupancy_change += current_occupancy_change;
        max_occupancy = max(max_occupancy, occupancy_change);
    }
    
    return max_occupancy;
}

int main(int argc, char** args) {
    //vector<tuple<int,int>> guest_dates{{1, 2}, {1, 3}, {2, 4}, {2, 3}};
    vector<tuple<int,int>> guest_dates{{1, 10}, {5, 20}, {2, 4}, {11, 14}, {}};
    
    auto result = find_busiest_day(guest_dates);
    
    cout << "result: " << result;
    // for(auto num: result) {
    //     cout << " " << num;
    // }
    
    return 0;
}
