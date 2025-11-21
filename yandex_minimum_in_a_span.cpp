//yandex task 11. Минимум на отрезке
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

//¡use comma as a delimiter for it to work in online compilers!
constexpr char delimiter = ' ';

tuple<int,int> input_number_amounts() {
    string input; cin >> input;
    stringstream ss(input);
    string numbers_amount,window_size;
    getline(ss, numbers_amount, delimiter);
    getline(ss, window_size, delimiter);
    return make_tuple(stoi(numbers_amount), stoi(window_size));
}

vector<int> input_numbers() {
    string input,str_number; cin >> input;
    stringstream ss(input);
    
    vector<int> numbers;
    while(getline(ss, str_number, delimiter)) {
        numbers.push_back(stoi(str_number));
    }
    return numbers;
}

string vector_to_string(const vector<int>& elements) {
    stringstream ss;
    for(auto element: elements) {
        ss << element << ", ";
    }
    ss << endl;
    return ss.str();
}

int output_from_window(const vector<int>& all_numbers, int start, int end) {
    int smallest_number = numeric_limits<int>::max();
    //cout << "checking window " << start << " -> " << end << endl;
    for (int i_number = start; i_number <= end; i_number++) {
        if (smallest_number > all_numbers[i_number]) {
            smallest_number = all_numbers[i_number];
        }
    }
    //cout << "smallest_number: " << smallest_number << endl;
    return smallest_number;
}

vector<int> all_window_outputs(const vector<int>& all_numbers, int window_size) {
    vector<int> outputs;
    
    int start = 0;
    int end = window_size-1;
    
    while (
        end < all_numbers.size()    
    ) {
        auto current_output = output_from_window(all_numbers, start, end);
        
        outputs.push_back(current_output);
        
        start++;
        end++;
    }
    
    return outputs;
}

int main() 
{
    const auto [numbers_amount,window_size] = input_number_amounts();

    vector<int> numbers = input_numbers();

    if (numbers.size() != numbers_amount) {
        throw runtime_error("the amount of numbers differs");
    }

    //cout << "window_size: " << window_size << endl;
    //cout << "numbers: " << vector_to_string(numbers);
    
    for (
        auto output:
        all_window_outputs(numbers, window_size)
    ) {
        cout << output << endl;
    }
    
	return 0;
}
