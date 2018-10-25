#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int src = x;
        int res = 0;
        while(x>0){
            res = 10*res + x%10;
            x /= 10;
        }
        if(src == res)return true;
        
        return false;
    }
};

int main()
{
    Solution s;
    s.isPalindrome(121);
    return 0;
}

