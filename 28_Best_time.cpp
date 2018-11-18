#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = 0; i < (int)prices.size(); ++i){
            for(int j = i + 1; j < (int)prices.size(); ++j){
                if(prices[j] < prices[i])continue;
                if(prices[j] - prices[i] > max)max = prices[j] - prices[i];
            }
        }

        return max;
    }
};

int main()
{
    vector<int> v{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(v) << endl;;
    return 0;
}

