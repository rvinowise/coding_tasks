/* 
*/
#include <iostream>
#include<thread>
#include<mutex>
#include<unordered_set>

using namespace std;



int most_popular_number(array<size_t, 2> window) {
    if (window[0] > window[1]) {
        return 0;
    }
    return 1;
}

int most_popular_number_amount(array<size_t, 2> window) {
    return window[most_popular_number(window)];
}

int window_size(array<size_t, 2> window) {
    return window[0] + window[1];
}

size_t longest_part(vector<int> numbers, size_t gap) {
    //unordered_set<int> window;
    array<size_t, 2> window;
    
    size_t substitutions_left{gap};
    
    size_t max_lenght{0};
    size_t left{0};
    size_t right{0};
    
    while(right < numbers.size()) {
        size_t current_window_size = right-left+1;
        
        cout 
            << "current_window_size=" << current_window_size 
            << " max_lenght=" << max_lenght 
            << " left=" << left
            << " right=" << right
            << endl;
        int incoming_number = numbers[right];
        window[incoming_number]++;

        cout 
            << "incoming number=" << incoming_number
            << " most_popular_number=" << most_popular_number(window) 
            << " amount=" << most_popular_number_amount(window)
            << endl;

        if (current_window_size-gap > most_popular_number_amount(window)) {
            size_t outcoming_number = numbers[left];
            window[outcoming_number]--;
            
            left++;
            
            cout 
                << "shrink the window, left=" << left 
                << " outcoming_number=" << outcoming_number
                << " window[outcoming_number]=" << window[outcoming_number]
                << endl;
            
        } else {
            max_lenght = max(max_lenght, current_window_size);
        }
        ++right;
        cout << endl;
    }
    
    return max_lenght;
}

struct Test {
    void test1() {
        vector<int> numbers{0,0,0,1,0,0,1,1,0,0,1,0};
        cout << longest_part(numbers, 1) << endl;
        //assert(longest_part(numbers, 1) == 6);
        
        vector<int> numbers1{0,0,1,1,0,0,1,1,0,0};
        cout << longest_part(numbers1, 1) << endl;
        //assert(longest_part(numbers1, 1) == 3);
        
        vector<int> numbers2{0,1,1,1};
        cout << longest_part(numbers2, 1) << endl;
        //assert(longest_part(numbers2, 1) == 4);
    }
};

int main(int argc, char** args) {
    Test test;
    test.test1();
    
    //size_t longest = longest_part(numbers, 1);
    
    //cout << "result: " << weasel.weight << " " << weasel2.weight << endl;


    
    return 0;
}
