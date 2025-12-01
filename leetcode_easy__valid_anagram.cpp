/* i knew the algorithm forom the explanations of many previous tasks */

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> chars1{};
        array<int, 26> chars2{};
        for(auto symbol: s) {
            chars1[symbol-'a']++;
        }
        for(auto symbol: t) {
            chars2[symbol-'a']++;
        }
        return chars1==chars2;
    }
};
