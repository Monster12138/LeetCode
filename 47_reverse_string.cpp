#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        size_t size = s.size();
        for(int i = 0; i < size/2.0; ++i){
            char tmp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = tmp;
        }
        return s;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

