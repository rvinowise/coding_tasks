//yandex task 2. Ближайшее число
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

constexpr char delimiter = ',';


tuple<vector<int>, int> get_input() {
    string str_numbers_amount; cin >> str_numbers_amount;
    int numbers_amount = stoi(str_numbers_amount);
    
    string str_numbers; cin >> str_numbers;
    stringstream ss(str_numbers);
    string str_number;
    vector<int> numbers;
    while(getline(ss, str_number, delimiter)) {
        numbers.push_back(stoi(str_number));
    }
    
    if (numbers.size() != numbers_amount) {
        throw invalid_argument("numbers amount doesn't match");
    }
    
    string str_searched_number; cin >> str_searched_number;
    int searched_number = stoi(str_searched_number);
    
    return make_tuple(numbers, searched_number);
}

int find_closest_number(vector<int> numbers, int searched_number) {
    //cout << "numbers.size = " << numbers.size() << endl;
    if (numbers.size() == 0) {
        throw invalid_argument("numbers shouldn't be empty");
    }
    int closest_number = numbers[0];
    for(const auto& number: numbers) {
        auto this_difference = abs(searched_number - number);
        auto closest_difference = abs(closest_number - searched_number);
        // cout 
        //     << "checking number="<<number
        //     <<"; closest_number="<<closest_number
        //     << "; this_difference="<<this_difference
        //     << "; closest_difference="<<closest_difference
        //     << endl;
        if (this_difference < closest_difference) {
            closest_difference = this_difference;
            closest_number = number;
            // cout 
            //     << "updating closest_number="<<closest_number
            //     << "; closest_difference="<<closest_difference
            //     << endl;
        }
    }
    
    return closest_number;
}

int main() 
{
    const auto [numbers, searched_number] =
        get_input();

    //cout << "numbers.size = " << numbers.size() << endl;

    cout << find_closest_number(numbers, searched_number);

	return 0;
}
