#include <iostream>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

