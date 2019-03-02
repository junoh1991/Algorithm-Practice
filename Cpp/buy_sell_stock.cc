#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int max(int a, int b){
    return a > b ? a : b;    
}

int maxProfit(const vector<int>& prices){
    int maxPrice = 0;
    vector<int> highestPrices(prices.size());
    for (int i = prices.size() - 1; i >= 0; i--){
        maxPrice = max(maxPrice, prices[i]);
        highestPrices[i] = maxPrice;
    }

    int maxProfit = 0;
    int index = 0;
    for (int i : highestPrices){
        int profit = i - prices[index];
        index++;
        maxProfit = max(profit, maxProfit);
        cout << maxProfit << " ";
    }
    cout << endl;

    return maxProfit;
}


int main(){
    vector<int> prices{100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97}; 
    for (int i : prices) cout << i << " ";
    cout << endl;
    int max1 = maxProfit(prices);
    cout << "ans:" << max1 << endl;
}
