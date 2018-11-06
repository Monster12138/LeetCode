#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<int> db;
        db.push_back(nums[0]);
        int max = db[0];
        for(unsigned int i = 1; i < nums.size(); ++i){
            db.push_back(nums[i] > db[i - 1] + nums[i]?nums[i]:db[i-1]+nums[i]);
            if(db[i] > max)max = db[i];
        }
        return max;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

