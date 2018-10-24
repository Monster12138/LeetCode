#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
         int max_are = 0;
         for(unsigned int i = 0; i < height.size(); i++){
             for(unsigned int j = i+1; j < height.size(); j++){
                 int are = (j-i) * (height[i]<height[j]?height[i]:height[j]);
                 if(max_are < are)max_are = are;
             }
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

