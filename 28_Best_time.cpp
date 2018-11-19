#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int res =  0;
        for(int i = 0; i < (int)prices.size(); ++i){
            vector<int> tmp(prices.begin() + i, prices.end());
            sort(tmp.begin(), tmp.end());
            int max = tmp.back() - prices[i];
            if(max > res)res = max;
        }

        return res;
        */

        int size = prices.size();
        vector<int> db(size + 1, 0);

        int max_p = prices.back();
        for(int i = size - 1; i >=0; --i){
            if(prices[i] > max_p){
                max_p = prices[i];
                db[i] = db[i+1];
            }
            else{
                db[i] = max(max_p - prices[i], db[i+1]);
            }
        }
        return db[0];
    }
};

int main()
{
    vector<int> v{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(v) << endl;;
    return 0;
}

