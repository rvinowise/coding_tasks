//yandex task 1. Словарь синонимов
#include <iostream>
#include <sstream>
#include <tuple>
#include <map>
#include <limits>
#include <stdexcept>

using namespace std;

//¡yandex's delimiter (whitespace) doesn't work with online compilers. use comma to see the result!
constexpr char delimiter = ' ';

using Synonyms = map<string, string>;

int input_synonyms_amount() {
    string amount;
    cin >> amount;
    return stoi(amount);
}

tuple<string,string> input_word_pair() {
    string pair; cin >> pair;
    stringstream ss(pair);
    string word1, word2;
    getline(ss,word1,delimiter);
    getline(ss,word2);
    //cout << "word1= "<< word1 << " word2= " << word2 << endl;
    return make_tuple(word1, word2);
}

Synonyms input_synonyms(int amount) {
    Synonyms synonyms;
    for (size_t i_synonym = 0; i_synonym < amount; i_synonym++) {
        const auto [word1, word2] = input_word_pair();
        synonyms.insert({word1, word2});
        synonyms.insert({word2, word1});
    }
    return synonyms;
}

string input_checked_word() {
    string word;
    cin >> word;
    return word;
}

string find_synonym(Synonyms synonyms, string checked_word) {
    return synonyms[checked_word];
}

string map_as_string(const map<string, string>& words) {
    stringstream ss;
    for (const auto &item : words) {
        ss << item.first << " -> " << item.second << endl;
    }
    return ss.str();
}

int main() 
{
    auto synonyms_amount = input_synonyms_amount();
    //cout << "synonyms amount: " << synonyms_amount << endl;
    const auto synonyms = input_synonyms(synonyms_amount);
    //cout << "synonyms: " << endl << map_as_string(synonyms);
    
    const string checked_word = input_checked_word();
    //cout << "checked_word: " << checked_word;
    
    const string synonym = find_synonym(synonyms, checked_word);
    
    cout << synonym;
    
}
