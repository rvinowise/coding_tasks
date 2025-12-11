/* 
  yandex task #3 from here: https://habr.com/ru/articles/550088/
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<map>
#include<algorithm>
#include<ranges>
#include<sstream>

using namespace std;

string group_ranges(
    vector<int> numbers
) {
    ranges::sort(numbers);
    
    int prev_number{numbers.front()};
    vector<tuple<int,int>> ranges{
        make_tuple(prev_number, prev_number)
    };

    for(size_t i_number=1; i_number < numbers.size(); i_number++) {
        //cout << "i_number="<< i_number << endl;
        int incoming_number = numbers[i_number];
        //cout << "prev_number=" << prev_number << " incoming_number=" << incoming_number << endl;
        if (incoming_number == prev_number+1) {
            //cout << "incoming_number == prev_number-1" << endl;
            get<1>(ranges.back()) = incoming_number;
        } else {
            //cout << " ranges.push_back, incoming_number=" << incoming_number << endl;
            ranges.push_back(
                make_tuple(incoming_number, incoming_number)
            );
        }
        prev_number = incoming_number;
    }
    
    stringstream ss;
    for(auto [tail, head]: ranges) {
        if (tail==head) {
            ss << tail << ",";
        } else {
            ss << tail << "-" << head << ",";
        }
    }
    return ss.str().erase(ss.str().length()-1);
}

int main(int argc, char** args) {
    vector<int> numbers{1,4,5,2,3,9,8,11,0};
    
    auto result = group_ranges(numbers);
    
    cout << "result: " << result;
    // for(auto num: result) {
    //     cout << " " << num;
    // }
    
    //size_t longest = longest_part(numbers, 1);
    
    //cout << "result: " << weasel.weight << " " << weasel2.weight << endl;


    
    return 0;
}
