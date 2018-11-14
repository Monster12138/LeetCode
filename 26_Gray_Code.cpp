#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < pow(2, n); ++i){
            res.push_back(i);
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

