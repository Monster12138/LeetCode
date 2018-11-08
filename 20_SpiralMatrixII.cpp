#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res0;
        if(n == 0)return res0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int height = n, width = n;
        int hindex = 0, windex = 0;
        int count = 1;
        while(hindex < height/2.0 && windex < width/2.0){
            int i = hindex;
            for(int j = windex; j < width - windex; ++j){
                res[i][j] = count++;
            }

            int j = width - windex - 1;
            for(int i = hindex + 1; i < height - hindex; ++i){
                res[i][j] = count++;
            }

            i = height - hindex - 1;
            if(i > hindex && width > 1){
                for(int j = width - windex - 2; j >= windex; --j){
                    res[i][j] = count++;
                }
            }


            j = windex;
            if(j < width - windex - 1){
                for(int i = height - hindex - 2; i >= hindex + 1; --i){
                    res[i][j] = count++;
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
    int n = 7;
    vector<vector<int>> res = s.generateMatrix(n);

        for(int i = 0; i < n; ++i){
            for(int j = 0;j < n; ++j){
                cout << res[i][j] << " ";
            }
            cout<< endl;
        }
    return 0;
}

