#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

constexpr char delimiter = ',';

vector<int> input_walls() {
    string input; cin >> input;
    stringstream ss(input);
    string str_height;
    vector<int> walls;
    while(getline(ss, str_height, delimiter)) {
        walls.push_back(stoi(str_height));
    }
    return walls;
}

int find_greatest_volume(const vector<int>& walls) {
    int max_volume = 0;
    for (long wall_start=0; wall_start<walls.size(); wall_start++) {
        for (long wall_end=wall_start+1; wall_end<walls.size(); wall_end++) {
            int this_volume = min(walls[wall_start], walls[wall_end]) * abs(wall_start-wall_end);
            cout << "volume= " << this_volume
                << " start=" << wall_start
                << " end=" << wall_end
                << endl;

            max_volume = max(max_volume, this_volume);
        }    
    }
    return max_volume;
}

class Solution {
    public:
    int maxArea(const vector<int>& walls) {
        return find_greatest_volume(walls);
    }
};

// int main() {
//     auto walls = input_walls();

//     auto greatest_volume = find_greatest_volume(walls);
//     cout << greatest_volume;
// }
