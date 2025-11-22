//yandex task 7. Сумма номеров

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#include <span>

using namespace std;

//!yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ',';


vector<int> input_car_numbers(int numbers_amount) {
    vector<int> numbers;
    numbers.reserve(numbers_amount);
    
    string input; cin >> input;
    stringstream ss(input);
    string str_number;
    while(getline(ss, str_number, delimiter)) {
        numbers.push_back(stoi(str_number));
    }
    
    if (numbers.size() != numbers_amount) {
        throw invalid_argument("amount or car numbers differs");
    }
    return numbers;
}

bool is_span_with_fav_number(
    const vector<int>& car_numbers, 
    int fav_number, 
    size_t start, 
    size_t end
) {
    int sum = 0;
    for(size_t i_car=start; i_car < end; i_car++) {
        sum += car_numbers[i_car];
    }
    if (sum == fav_number) {
        return true;
    }
    return false;
}

int sum_within_span(
    span<const int> numbers
) {
    int sum = 0;
    for(const int number: numbers) {
        //cout << "sum_within_span= " << sum <<endl;
        sum += number;
    }
    //cout << "sum_within_span= " << sum<<endl;
    return sum;
}

int sum_within_span(
    const vector<int>& car_numbers, 
    size_t start, 
    size_t end
) {
    int sum = 0;
    for(size_t i_car=start; i_car < end; i_car++) {
        sum += car_numbers[i_car];
    }
    return sum;
}

void announse_found_span(size_t start, size_t end, const vector<int>& numbers) {
    cout << "found span: " << start << "->" << end <<" [";
    for (size_t i = start; i <= end; i ++) {
        cout << numbers[i] << " ";
    }
    cout << "]" << endl;
}

int find_spans_giving_fav_number(const vector<int>& car_numbers, int fav_number) {
    int spans_amount = 0;
    int start = 0, end = 0;
    while (
        (end < car_numbers.size())
    ) {
        auto window = span(car_numbers).subspan(start,end+1);
        auto sum_in_span = sum_within_span(car_numbers, start, end+1);
        //cout << "check window " << start << "->" << end << endl;
        //cout << "sum_in_span= " << sum_in_span << endl;
        if (sum_in_span == fav_number) {
            spans_amount++;
            announse_found_span(start, end, car_numbers);
            //window = numbers_span.subspan(window.begin()+1, window.end()+1);
            start+=1;
            end+=1;
        } else if (sum_in_span < fav_number) {
            //cout << "sum in span " << start << "->" << end <<  " = " << sum_in_span << endl;
            //window = numbers_span.subspan(window.begin(), window.end()+1);
            end+=1;
            //cout << "now span is " << start << "->" << end << endl;
        }else if (sum_in_span > fav_number) {
            start+=1;
        }
    }
    return spans_amount;
}

int main() {
    string input,str_cars_amount,str_fav_number; cin >> input;
    stringstream ss(input);
    getline(ss,str_cars_amount,delimiter);
    getline(ss,str_fav_number,delimiter);
    int cars_amount = stoi(str_cars_amount);
    int fav_number = stoi(str_fav_number);
    
    vector<int> car_numbers = input_car_numbers(cars_amount);
    int spans_amount = find_spans_giving_fav_number(car_numbers, fav_number);
    
    //cout << "there are " << spans_amount << " spans making " << fav_number << endl;
    cout << spans_amount;
    
    return 0;
}
