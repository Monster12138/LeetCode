#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int btod(int *arr, int size){
        int num = 0;
        for(int i = size -1; i >= 0; --i){
            if(1 == *(arr + i)){
                num += pow(2, size - i - 1);
            }
        }
        return num;
    }

    bool invector(const vector<int> &res, int num){
        for(int i = 0; i < (int)res.size(); ++i){
            if(res[i] == num)return true;
        }
        return false;
    }

/*
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(0 == n)return res;
        int arr[n] = {0};
        int count = pow(2,n);
        for(int i = 0; i < count; ++i){
            for(int j = 0; j < n; ++j){
                arr[j] = !arr[j];
                int num = btod(arr, n);
                if(!invector(res, num)){
                    res.push_back(num);
                    break;
                }
                else arr[j] = !arr[j];
            }
        }
        return res;
    }
    */
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> res;
        for(int i=0;i<size;i++){
            int graycode = i ^ (i>>1);
            res.push_back(graycode);
        }
        return res;
    }

};

int main()
{
    Solution s;
    vector<int> res = s.grayCode(2);
    for(int i = 0; i < (int)res.size(); ++i){
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}

