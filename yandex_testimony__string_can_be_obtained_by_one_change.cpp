/* 
yandex testimony task#  9 from here: https://habr.com/ru/articles/550088/
*/
#include <iostream>
#include<vector>
#include<mutex>
#include<map>
#include<algorithm>
#include<ranges>
#include<sstream>

using namespace std;


bool can_be_obtained(string str1, string str2) {
    if (abs((long long)str1.size() - (long long)str2.size()) > 1) {
        return false;
    }
    
    size_t i_str1{0};
    size_t i_str2{0};
    size_t diff_amount{0};
    while(i_str1 < str1.size() && i_str2 < str2.size()) {
        if (str1[i_str1] != str2[i_str2]) {
            if(++diff_amount > 1) {
                return false;
            }
            
            if (str1.size() > str2.size()) {
                ++i_str1;
            } else if (str1.size() < str2.size()) {
                ++i_str2;
            }else {
                ++i_str1;
                ++i_str2;
            }
        } else {
            ++i_str1;
            ++i_str2;
        }
    }
    return true;
}

int main(int argc, char** args) {
    
    std::cout << "(\"pale\", \"ple\"): " << std::boolalpha << can_be_obtained("pale", "ple") << std::endl; // True (deletion)
    std::cout << "(\"pales\", \"pale\"): " << std::boolalpha << can_be_obtained("pales", "pale") << std::endl; // True (deletion)
    std::cout << "(\"pale\", \"bale\"): " << std::boolalpha << can_be_obtained("pale", "bale") << std::endl; // True (replacement)
    std::cout << "(\"pale\", \"bake\"): " << std::boolalpha << can_be_obtained("pale", "bake") << std::endl; // False (two replacements)
    std::cout << "(\"abc\", \"acd\"): " << std::boolalpha << can_be_obtained("abc", "acd") << std::endl; // false
    std::cout << "(\"abc\", \"ab\"): " << std::boolalpha << can_be_obtained("abc", "ab") << std::endl; // True (deletion)
    std::cout << "(\"ab\", \"abc\"): " << std::boolalpha << can_be_obtained("ab", "abc") << std::endl; // True (deletion)
    std::cout << "(\"abc\", \"ade\"): " << std::boolalpha << can_be_obtained("abc", "ade") << std::endl; // False (two changes)
    // for(auto num: result) {
    //     cout << " " << num;
    // }
    
    return 0;
}
