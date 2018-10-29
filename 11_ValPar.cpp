#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        unsigned int i = 0;
        while( i < s.size() ){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                cs.push(s[i]);
                ++i;
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(cs.empty())return false;
                if(s[i] == ')'){
                    if(cs.top() != '(')return false;
                }
                else if(s[i] == '}'){
                    if(cs.top() != '{')return false;
                }
                else {
                    if(s[i] == ']'){
                        if(cs.top() != '[')return false;
                    }
                }
                cs.pop();
                ++i;
            }
        }

        if(cs.empty())return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isValid("[");
    return 0;
}

