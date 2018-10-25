#include <iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
/*        vector<int> vec;
        while(x!=0){
            int i = x%10;
            x /= 10;
            vec.push_back(i);
        }
        long long  res = 0;
        for(unsigned int i = 0; i < vec.size(); i++){
            cout<<vec[i];
            res += vec[i] * pow(10, vec.size() - i - 1);
        }
        cout<<endl;
        cout<<res<<endl;
        if(res >= pow(2,31) - 1 || res <= -pow(2,31))return 0;
        return res;
        */
        int array[100];
        int size = 0;
        while(x!=0){
            array[size++] = x%10;
            x /= 10;
        }
        long long  res = 0;
        for(int i = 0; i < size; i++){
            res += array[i] * pow(10,size - i - 1);
        }
        if(res >= pow(2,31) - 1 || res <= -pow(2,31))return 0;
        return res;
 
    }
};

int main()
{
    Solution s;
    int res = s.reverse(-123);
    cout<<res<<endl;
    return 0;
}

