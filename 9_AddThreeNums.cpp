#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
/*
    bool isSame(const vector<int>& v1, const vector<int>& v2){
        if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2])return true;

        return false;
        while(i<v1.size()){
            if(v1[i] != v2[i])return false;
            ++i;
        }

        return true;
    }
*/

    bool ainb(const vector<vector<int>>& b,const vector<int>& a){
        unsigned int i = 0;
        while( i < b.size() ){
            if(b[i][0] == a[0] && b[i][1] == a[1] && b[i][2] == a[2])return true;
            ++i;
        }

        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)return res;
        sort(nums.begin(), nums.end());
/*      while(i < nums.size() - 2){
            if(i != 0 && nums[i] == nums[i-1]){
                ++i;
                continue;
            }
            if(nums[i]>0)break;
            unsigned int j = i+1;
            while(j < nums.size()){
                unsigned int k = j+1;
                int sum2 = nums[i] + nums[j];
                while(k < nums.size()){
                    vector<int> tmp;
                    if(sum2 + nums[k] == 0){
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        sort(tmp.begin(),tmp.end());
                        if(!ainb(res, tmp))res.push_back(tmp);
                    }
                    ++k;
                }
                ++j;
            }
            ++i;
        }
*/
        for(unsigned int i = 0; i <nums.size(); ++i){
            int left = i + 1, right = nums.size() - 1;
            if( i > 0 && nums[i] == nums[i-1] )continue;
            while(left < right){
                if(nums[left] + nums[right] == -nums[i]){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while( left < right && nums[left] == nums[left+1] )++left;
                    while( left < right && nums[right] == nums[right - 1] )--right;
                    ++left;
                    --right;
                }
                else if(nums[left] + nums[right] > -nums[i])right--;
                else left++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> vec{-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> res = s.threeSum(vec);
    for(unsigned int i = 0; i < res.size(); ++i){
        for(int j = 0;j < 3; ++j){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}

