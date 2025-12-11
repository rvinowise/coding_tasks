/* 
yandex testimony task #8 from here: https://habr.com/ru/articles/550088/
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<map>
#include<algorithm>
#include<ranges>
#include<sstream>

using namespace std;

constexpr float epsylon = 0.00001;

struct Point {
    float x;
    float y;
    
    Point(initializer_list<float> coord):
        x(*coord.begin()),
        y(*(coord.begin()+1))
    {}
        
    bool operator<(const Point& other) const {
        if (
            (abs(x-other.x) < epsylon) && 
            (abs(y-other.y) < epsylon)
           ) {
            return false;
        }
        return tie(x, y) < tie(other.x, other.y);
    }
    
    // bool operator==(const Point& other) const {
    //     return tie(x, y) == tie(other.x, other.y);
    // }
};

bool is_symmetrical(vector<Point> points) {
    set<Point> set_points;
    
    float min_x{numeric_limits<float>::max()};
    float max_x{numeric_limits<float>::min()};
    for(auto point: points) {
        min_x = min(min_x, point.x);
        max_x = max(max_x, point.x);
        set_points.insert(point);
    }
    
    float axis_x = (max_x + min_x) / 2;
    cout << "axis_x= " << axis_x << "=" << max_x << "+" << min_x << "div by 2" << endl;
    //int axis_x = (max_x - min_x) / 2 + min_x;
    
    for(auto point: points) {
        Point mirrored{
            (axis_x - point.x) + axis_x,
            //axis_x*2 - point.x,
            point.y
        };
        
        if (!set_points.contains(mirrored)) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char** args) {
    //vector<tuple<int,int>> guest_dates{{1, 2}, {1, 3}, {2, 4}, {2, 3}};
    vector<Point> points{{1, 10}, {2, 10}, {-1, 20}, {4, 20}};
    
    auto result = is_symmetrical(points);
    
    cout << boolalpha << "result: " << result;
    // for(auto num: result) {
    //     cout << " " << num;
    // }
    
    return 0;
}
