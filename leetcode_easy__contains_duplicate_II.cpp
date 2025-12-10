/* leetcode easy 219. Contains Duplicate II (= contains nearby duplicate)
*/

#include <iterator>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& numbers, int in_distance) {
        if (in_distance < 1) {
            return false;
        }
        size_t distance = in_distance;
        
        set<int> window;
        for(
            size_t i=0; 
            i<= min(distance, numbers.size()-1); 
            i++
        ) {
            if (window.contains(numbers[i])) {
                return true;
            }
            window.insert(numbers[i]);
        }

        cout << std::distance(window.begin(), window.find(0));

        if (distance >= numbers.size()-1) {
            return false;
        }

        for(
            size_t start=1; 
            start < numbers.size()-distance; 
            start++
        ) {
            int leaving_num = numbers[start-1];
            int incoming_num = numbers[start+distance];
            
            window.erase(leaving_num);
            if (
                window.find(incoming_num) != window.end()
            ) {
                
                return true;
            }
            window.insert(incoming_num);
        }
        return false;
    }
};
