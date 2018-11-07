#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())return res;
        int height = matrix.size(), width = matrix[0].size();
        int hindex = 0, windex = 0;
        while(hindex < height/2.0 && windex < width/2.0){
            int i = hindex;
            for(int j = windex; j < width - windex; ++j){
                res.push_back(matrix[i][j]);
            }

            int j = width - windex - 1;
            for(int i = hindex + 1; i < height - hindex; ++i){
                res.push_back(matrix[i][j]);
            }

            i = height - hindex - 1;
            if(i > hindex && width > 1){
                for(int j = width - windex - 2; j >= windex; --j){
                    res.push_back(matrix[i][j]);
                }
            }


            j = windex;
            if(j < width - windex - 1){
                for(int i = height - hindex - 2; i >= hindex + 1; --i){
                    res.push_back(matrix[i][j]);
                }
            }
            

            ++hindex;
            ++windex;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> vec = {{1},{2},{3}};
   // vector<vector<int>> vec = {{1,2,3,4},{5,6,7,8}};
    vector<vector<int>> vec = {{1,2,3},{5,6,7},{9,10,11}};


    vector<int> res = s.spiralOrder(vec);
    for(unsigned int i = 0; i < res.size(); ++i){
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}

