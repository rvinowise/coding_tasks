// leetcode 136 single number
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <cmath>

using namespace std;


int single_number(vector<int>& numbers) {
    //map<int, int> number_to_occurences;
    set<int> occurences;
    
    for(size_t i_number=0; i_number<numbers.size(); i_number++) {
        //number_to_occurences[numbers[i_number]]++
        auto current_number = numbers[i_number];
        if (occurences.contains(current_number)) {
             occurences.erase(current_number);
        } else {
            occurences.insert(current_number);
        }
    }
    
    return *occurences.begin();
}

class Solution {
public:
    int singleNumber(vector<int>& numbers) {
        return single_number(numbers);
    }
};




// int main() {
 
    
//     vector<int> numbers{4,1,2,1,2}; // should return 4
//     auto number = single_number(numbers);
 
//     cout << number ;
    
 
//     return 0;   
// }

