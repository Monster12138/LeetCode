#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = 1;
        for(int i = 0; i < 31; ++i){
            if(n == num << i)return true;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

