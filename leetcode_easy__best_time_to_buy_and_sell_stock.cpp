//leetcode 121. best time to buy and sell stock
/* bruteforce solution, TLE at the end */
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int max_profit_from_day(const vector<int>& prices, size_t start) {
    int max_profit = 0;
    
    for(size_t end=start+1; end < prices.size(); end++) {
        int profit = prices[end] - prices[start];
        max_profit = max(max_profit, profit);
    }
    
    return max_profit;
}

int find_largest_profit(const vector<int>& prices) {
    int max_profit = 0;
    for(size_t start=0; start < prices.size()-1; start++) {
        int profit = max_profit_from_day(prices, start);
        max_profit = max(max_profit, profit);
    }
    
    return max_profit;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return find_largest_profit(prices);
    }
};

int main()
{
    vector<int> prices{7,1,5,3,6,4};
    int result = find_largest_profit(prices);
    
    std::cout << "result:" << result;

    return 0;
}
