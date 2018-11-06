#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> tmp;
        vector<vector<int>> res;
        if(nums.size() == 0)return res;

        vec.push_back(nums[0]);
        res.push_back(vec);
        for(unsigned int i = 1; i<nums.size();++i){
            tmp = res;
            res.clear();
            for(unsigned int j = 0; j < tmp.size(); ++j){
                tmp[j].push_back(nums[i]);
                res.push_back(tmp[j]);
                for(unsigned int k = tmp[j].size() - 1; k > 0 ; --k){
                    int t = tmp[j][k];
                    tmp[j][k] = tmp[j][k-1];
                    tmp[j][k-1] = t;
                    res.push_back(tmp[j]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.permute(nums);
    for(unsigned int i = 0; i<res.size();++i){
        for(unsigned int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}

