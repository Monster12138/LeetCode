#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int f0 = 1, f1 = 1;
        if(n < 2)return 1;
        for(int i = 1; i < n; ++i){
            f1 += f0;
            f0 = f1 - f0;
        }
        return f1;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(5) <<endl;
    return 0;
}

