/*
it's written in the implementation of the function
std::set_intersect (#include <algorithm>)
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<unordered_set>
#include<algorithm>
#include<ranges>

using namespace std;

vector<int> get_intersection(
    vector<int>& numbers1,
    vector<int>& numbers2
) {
    vector<int> result;
    
    ranges::sort(numbers1);
    ranges::sort(numbers2);
    
    size_t index1{0};
    size_t index2{0};
        
    while(
        index1 < numbers1.size()
        &&
        index2 < numbers2.size()
    ) {
        int number1 = numbers1[index1];
        int number2 = numbers2[index2];
        if (number1 < number2) {
            ++index1;
        } else {
            if (number1 == number2) {
                result.push_back(number1);
            }
            ++index2;
        }
    }
    
    return result;
}

int main(int argc, char** args) {
    vector<int> numbers1{1, 2, 3, 2, 0};
    vector<int> numbers2{5, 1, 2, 7, 3, 2};
    
    auto result = get_intersection(numbers1, numbers2);
    
    cout << "result:";
    for(auto num: result) {
        cout << " " << num;
    }
    
    //size_t longest = longest_part(numbers, 1);
    
    //cout << "result: " << weasel.weight << " " << weasel2.weight << endl;


    
    return 0;
}
