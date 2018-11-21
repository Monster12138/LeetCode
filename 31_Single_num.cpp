#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0 ; i + 1 < (int)nums.size(); ++i){
            nums[i+1] ^= nums[i];
        }
        
        return nums[nums.size()-1];
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

