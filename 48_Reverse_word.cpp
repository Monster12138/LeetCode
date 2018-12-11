#include <iostream>
#include <string>
using namespace std;

static const auto _=[]{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        int len = s.size();
        do{
            end = s.find(' ', start);
            if(end == -1)end = len;
            int wlen = end - start;
            for(int i = start; i < start + (wlen/2.0); ++i)
            {
                char tmp = s[i];
                s[i] = s[end - i -1 + start];
                s[end - i - 1 + start] = tmp;
            }
            start = end + 1;
        }while(end < len);
        return s;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

