#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> tmp;
        vector<vector<int>> res;

        vec.push_back(nums[0]);
        res.push_back(vec);
        for(unsigned int i = 1; i<nums.size();++i){
            tmp = res;
            for(unsigned int j = 0; j < tmp.size(); ++j){
                
            }
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

