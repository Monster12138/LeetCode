#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*     1.0
        int  i = nums.size() - 1,length = nums.size(), end = 0;
        while(i>0){
            if(nums[i] == nums[i-1])end = i;
            else {
                --i;
                continue;
            }
            while(i>0 && nums[i] == nums[i-1]){
                --i;
            }
            for(int j = 1; end + j < length; ++j){
                nums[i+j] = nums[end+j];
            }
            length -= (end - i);
        }
        return length;
        */
/*2.0
        if(nums.empty())return 0;
        unsigned int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[j] != nums[j-1]){
                nums[++i] = nums[j];
            }
            ++j;
        }
        return i+1;
*/
        if(nums.empty())return 0;
        return std::distance(nums.begin(),unique(nums.begin(),nums.end()));
    }
};

int main()
{
    vector<int> vec = {1,1,1,1,1,1,1};
    Solution s;
    int res = s.removeDuplicates(vec);
    cout << res << endl;
    for(int i = 0; i < res; ++i)
    {
        cout << vec[i] << ' ';
    }
    cout << endl;
    return 0;
}

