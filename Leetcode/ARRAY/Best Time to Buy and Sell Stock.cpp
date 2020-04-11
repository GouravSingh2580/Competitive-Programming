/*Runtime: 4 ms, faster than 97.49% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock.*/


class Solution {
public:
    int maxProfit(vector<int> &prices) {
    int paisa = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        paisa = max(paisa, prices[i] - minPrice);
    }
    return paisa;
}
};
