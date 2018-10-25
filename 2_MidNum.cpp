#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        double res = 0;
        vector<int> num;
        unsigned int i = 0, j = 0;
        while(i<nums1.size() || 
              j<nums2.size())
        {
            if(i >= nums1.size()){
                num.push_back(nums2[j]);
                j++; 
            }
            else if(j >= nums2.size()){
                num.push_back(nums1[i]);
                i++; 
            }
            else {
                if(nums1[i] < nums2[j]){
                    num.push_back(nums1[i]);
                    i++; 
                }
                else {
                    num.push_back(nums2[j]);
                    j++;
                }
            }
        }
        if(count % 2 == 0){
            res = (num[count/2 - 1] + num[count/2])/2.0;
        }
        else {
            res = num[count/2];
        }
        return res;
    }
};
int main()
{
    vector<int> n1;
    vector<int> n2;
    n1.push_back(1);
    n1.push_back(3);

    n2.push_back(2);
    Solution s;
    double res = s.findMedianSortedArrays(n1, n2);
    printf("%lf\n", res);
    return 0;
}

