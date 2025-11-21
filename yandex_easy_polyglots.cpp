//yandex task 3. Полиглоты

#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

//!yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ',';


tuple<
    set<string>, 
    vector<set<string>>
>
input_languages_of_students(int students_amount) {
    set<string> all_languages;
    vector<set<string>> student_languages;
    
    for(size_t i_student = 0; i_student < students_amount; i_student ++) {
        student_languages.push_back(set<string>());
        string str_languages_amount; cin >> str_languages_amount;
        int languages_amount = stoi(str_languages_amount);
        for(size_t i_language = 0; i_language < languages_amount; i_language ++) {
            string language; cin >> language;
            all_languages.insert(language);
            student_languages[i_student].insert(language);
        }
    }
    return make_tuple(all_languages, student_languages);
}

bool every_student_knows(
    const vector<set<string>>& student_languages, 
    string language
) {
    for (const auto& languages: student_languages) {
        if (!languages.contains(language)) {
            return false;
        }
    }
    return true;
}

set<string> find_popular_languages(
    const set<string>& all_languages,
    const vector<set<string>>& student_languages
) {
    set<string> popular_languages;
    for(const auto language: all_languages) {
        if (every_student_knows(student_languages, language)) {
            popular_languages.insert(language);
        }
    }
    return popular_languages;
}

int main() {
    
    string str_students_amount; cin >> str_students_amount;
    int students_amount = stoi(str_students_amount);
    
    auto [all_languages, student_languages] = input_languages_of_students(students_amount);
    auto popular_languages = find_popular_languages(all_languages, student_languages);
    
    cout << popular_languages.size() << endl;
    for (const auto& language: popular_languages ) {
        cout << language << endl;
    }
    cout << all_languages.size() << endl;
    for (const auto& language: all_languages ) {
        cout << language << endl;
    }
    
    return 0;
}
