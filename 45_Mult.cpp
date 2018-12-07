#include <iostream>
#include <vector>
using namespace std;

static const auto _=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int tmp = 1;
        vector<int> ret(nums.size(),1);
        for(int i = 1; i < len; i++)
        {
            tmp *= nums[i-1];
            ret[i] *= tmp;
        }
        tmp = 1;
        for(int i = len - 2; i >= 0; --i)
        {
            tmp *= nums[i+1];
            ret[i] *= tmp;
        }
        return ret;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

