#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        unsigned int i = 0;
        while(i < strs[0].size()){
            unsigned int j = 1;
            while(j < strs.size()){
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])break;
                j++;
            }
            if(j == strs.size())res += strs[0][i];
            else break;
            i++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> vec = {"abcde", "cbc", "ab"};
    string res = s.longestCommonPrefix(vec);
    cout << res <<endl;

    return 0;
}

