#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res, minnum = INT32_MAX;
        for(unsigned int i = 0; i < nums.size(); ++i){
            unsigned int left = i + 1, right = nums.size() - 1; 
            int target2 = target - nums[i];
            while(left < right){
                cout<< nums[i] << nums[left] << nums[right] <<endl;
                cout<<nums[i] + nums[left] + nums[right]<<endl;
                if(nums[left] + nums[right] > target2){
                    if(abs(target2 - nums[left] - nums[right]) < minnum){
                        minnum = abs(target2 - nums[left] - nums[right]);
                        res = nums[i] + nums[left] + nums[right];
                    }
                    --right;
                }
                else {
                    if(abs(target2 - nums[left] - nums[right]) < minnum){
                        minnum = abs(target2 - nums[left] - nums[right]);
                        res = nums[i] + nums[left] + nums[right];
                    }
                    ++left;
                }

                cout<<minnum<<endl;
//                while(left < right - 1 && nums[left] == nums[left + 1])++left;
//                while(left < right - 1&& nums[right] == nums[right - 1])--right;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
    cout << s.threeSumClosest(vec, -59) <<endl;
    return 0;
}

