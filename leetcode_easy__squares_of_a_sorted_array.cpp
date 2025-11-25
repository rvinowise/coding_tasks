// leetcode 977 squares of a sorted array

/* this is not the most intuitive solution, but it's faster than resorting to a sorting function */
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <cmath>

using namespace std;

tuple<
    vector<int>,
    vector<int>
>
separate_negatives(const vector<int> numbers) {
    size_t last_negative_index = -1;
    for (size_t i_number = 0; i_number < numbers.size(); i_number++) {
        if (numbers[i_number] < 0) {
            last_negative_index = i_number;
        } else {
            break;
        }
    }
    return tuple(
        vector<int>(numbers.begin(), numbers.begin()+last_negative_index+1),  
        vector<int>(numbers.begin()+last_negative_index+1, numbers.end())
    );
}


string vector_as_text(const vector<int>& numbers) {
    stringstream ss;
    for(size_t number: numbers) {
        ss << number << " ";
    }
    return ss.str();
}

vector<int> square_two_vectors(const vector<int>& negatives, const vector<int>& positives) {
    int last_negative_index = negatives.size()-1;
    int last_positive_index = 0;
    vector<int> result;
    
    while(
        last_negative_index >= 0
        ||
        last_positive_index < positives.size()
    ) {
        
        if (last_negative_index == -1) {
            result.push_back(pow(positives[last_positive_index], 2));
            last_positive_index++;
            continue;
        } else if (last_positive_index == positives.size()) {
            result.push_back(pow(negatives[last_negative_index], 2));
            last_negative_index--;
            continue;
        }
        
        // cout 
        //     << " last_negative_index= " << last_negative_index
        //     << " last_positive_index= " << last_positive_index
        //     << " negatives[last_negative_index]= " << negatives[last_negative_index]
        //     << " positives[last_positive_index]= " << positives[last_positive_index]
        //     << endl;

        if (
            abs(negatives[last_negative_index]) < positives[last_positive_index]
        ) {
            result.push_back(pow(negatives[last_negative_index], 2));
            //cout << "pushing negative, result= " << vector_as_text(result) << endl;
            last_negative_index--;
        } else {
            result.push_back(pow(positives[last_positive_index], 2));
            //cout << "pushing positive, result= " << vector_as_text(result) << endl;
            last_positive_index++;
        }
    }
    
    return result;
}

vector<int> square_numbers(const vector<int>& numbers) {
    const auto[negatives, positives] = separate_negatives(numbers);
    
    cout << "negatives: ";
    for(const auto& negative: negatives) {
        cout << negative << " ";
    }
    cout << "positives: ";
    for(const auto& positive: positives) {
        cout << positive << " ";
    }
    cout << endl;
    
    const auto squared_result = square_two_vectors(negatives, positives);
    
    return squared_result;
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        return square_numbers(nums);
    }
};

// int main() {
 
//     vector<int> nums{-4,-1,0,3,10};
//     auto result = square_numbers(nums);
    
//     cout << "squared result: ";
//     for(const auto& number: result) {
//         cout << number << " ";
//     }
    
//     return 0;   
// }

