//leetcode 480 sliding window median
/* solving it after 1 hour after reading the solution on algorithm.monster */

#include <vector>
#include <array>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void print_elements(string name, const multiset<int>& elements) {
    cout << name << ":";
    for(auto element: elements) {
        cout << " " << element;
    }
    cout << endl;
}

int max_value(const multiset<int>& elements) {
    return *elements.rbegin();
}
int min_value(const multiset<int>& elements) {
    return *elements.begin();
}

bool remove_element(multiset<int>& elements, int element) {
    auto it = elements.find(element);
    if (it != elements.end()) {
        elements.erase(it);
        return true;
    }
    return false;
}

void swap_element(
    multiset<int>& src,    
    multiset<int>& dst,   
    int value
) {
    remove_element(src, value);
    dst.insert(value);
}



class Window {
public:
    Window(int _size): size(_size) {
        
    }
    
    double median() {
        // cout
        //     << " median: "
        //     << " max_value(lessers)=" << max_value(lessers)
        //     << " min_value(greaters)=" << min_value(greaters)
        //     << endl;
        if (size % 2 == 0) {
            // cout << "median is average" << endl; 
            return (static_cast<double>(max_value(lessers)) + min_value(greaters)) /2;
        }
        // cout << "median is max of lessers (" <<max_value(lessers) << ")" << endl;
        return max_value(lessers);
    }
    
    void add(int next_value) {
        // cout
        //     << " add " << next_value
        //     <<endl;
        
        if (
            lessers.size() == 0
            ||
            max_value(lessers) > next_value
        ) {
            lessers.insert(next_value);    
            // cout
            //     << " lessers.insert " << next_value
            //     << endl;
        } else {
            greaters.insert(next_value);
            // cout
            //     << " greaters.insert " << next_value
            //     << endl;
        }
        
        // cout << "after adding " << next_value << ":" << endl;
        // print_elements("lessers", lessers);
        // print_elements("greaters", greaters);
        
        rebalance();
    }
    
    void remove(int value) {
        // cout
        //     << " remove " << value
        //     << endl;
        if (!remove_element(lessers, value)) {
            remove_element(greaters, value);
        }
        
        // cout << "after removal:" << endl;
        // print_elements("lessers", lessers);
        // print_elements("greaters", greaters);
        
        rebalance();
    }
    
private:

    void rebalance() {
        if (lessers.size() < greaters.size()) {
            // cout
            //     << " rebalance, lessers < greaters " 
            //     << endl;
            swap_element(
                greaters,
                lessers,
                min_value(greaters)
            );
        } else if (lessers.size() > greaters.size()+1) {
            // cout
            //     << " rebalance, lessers > greaters+1 " 
            //     << endl;
            swap_element(
                lessers,
                greaters,
                max_value(lessers)
            );
        }
        
        // cout << "after rebalancing:" << endl;
        // print_elements("lessers", lessers);
        // print_elements("greaters", greaters);
    }

    int size;
    multiset<int> lessers;
    multiset<int> greaters;
    
};

vector<double> median_sliding_window(const vector<int>& numbers, int window_size) {
    Window window(window_size);
    for(int i=0; i< window_size; i++) {
        window.add(numbers[i]);
    }
    vector<double> medians{window.median()};
    
    for(int i_start=1; i_start <= numbers.size() - window_size; i_start++) {
        window.add(numbers[i_start+window_size-1]);
        window.remove(numbers[i_start-1]);
        medians.push_back(window.median());
    }
    return medians;
}



class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& numbers, int window_size) {
        return median_sliding_window(numbers, window_size);
    }
};

// int main() {
    
//     vector<int> numbers{1,4,2,3,6,7};
    
//     auto medians = median_sliding_window(numbers, 3);
    
//     cout << "final result:" << endl;
//     for(auto median: medians) {
//         cout << median << " ";
//     }
    
//     return 0;
// }
