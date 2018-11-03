#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* 1.0
        unsigned int i = 0;
        for(; i < nums.size(); ++i){
            if(target == nums[i])return i;
            if( i>0 && target < nums[i-1] && target > nums[i])return -1;
        }
        return -1;
        */
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            cout << nums[left] <<endl;
            cout << nums[mid] <<endl;
            cout << nums[right] << endl;
            if(nums[mid] == target)return mid;
            
            if(nums[mid] < nums[right]){
                if(target <= nums[right] && target >= nums[mid])left = mid + 1;
                else right = mid - 1;
            }
            else {
                if(target >= nums[left] && target <= nums[mid])right = mid - 1;
                else left = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> vec = {3,5,1};
    Solution s;
    cout << s.search(vec, 3) << endl;
    return 0;
}

