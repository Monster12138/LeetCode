#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res,tmp2,tmp;
        vector<int> vec;
        vector<int> vec3;
        vector<int> vec2;
        res.push_back(vec);
        if(nums.empty())return res;
        for(unsigned int j = 0; j < nums.size(); ++j){
            vec.clear();
            vec.push_back(nums[j]);
            vec3.push_back(j);
            tmp2.push_back(vec);
            res.push_back(vec);            
        }
        
        while(1){
            tmp = tmp2;
            tmp2.clear();
            vec2 = vec3;
            vec3.clear();
            for(unsigned int i = 0; i < tmp.size(); ++i){
                for(unsigned int j = vec2[i] + 1; j < nums.size(); ++j){
                    vec = tmp[i];
                    vec.push_back(nums[j]);
                    vec3.push_back(j);
                    tmp2.push_back(vec);
                    res.push_back(vec);
                    for(unsigned int k = 0; k < vec.size(); ++k){
                        cout<<vec[k]<<' ';
                    }
                    cout << endl;
                }
            }
            if(vec.size() == nums.size())break;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1,2,3};
    s.subsets(vec);
    return 0;
}

