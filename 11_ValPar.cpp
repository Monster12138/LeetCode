#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0)return false;
        stack<char> cs;
        unsigned int i = 0;
        while( i < s.size() ){
            if(s[i] == '(')cs.push(')');
            else if(s[i] == '{')cs.push('}');
            else if(s[i] == '[')cs.push(']');
            else {
                if(cs.empty() || cs.top() != s[i])return false;
                else cs.pop();
            }

            ++i;
        }
        if(cs.empty())return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("]");
    return 0;
}

