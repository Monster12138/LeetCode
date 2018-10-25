#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /* 暴力法
           int max_are = 0;
           for(unsigned int i = 0; i < height.size(); i++){
           for(unsigned int j = i+1; j < height.size(); j++){
           int are = (j-i) * (height[i]<height[j]?height[i]:height[j]);
           if(max_are < are)max_are = are;
           }
           }
           return max_are;
           */

        int max_are = 0, i = 0, j = height.size() - 1;
        while(i<j){
            max_are = max(max_are,((j-i) * (height[i] < height[j]?height[i]:height[j])));
            height[i]<height[j]?++i:--j;
        }
        return max_are;
    }
};

int main()
{
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int res = s.maxArea(vec);
    cout << res <<endl;
    return 0;
}

