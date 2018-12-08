#include <iostream>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        if(n >= 4 && n%4 == 0)return false;
        return true;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

