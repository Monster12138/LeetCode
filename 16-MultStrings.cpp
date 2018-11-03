#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multChar(string& num1,char num2, int count){
        string tmp("");
        while(count){
            tmp+='0';
            --count;
        }
        int carry = 0;
        for(int i = num1.size() - 1; i >= 0; --i){
            int c = (num1[i] - '0') * (num2 - '0') + carry;
            if(c > 9){
                carry = c/10;
                c = c%10;
            }
            else {
                carry = 0;
            }
            tmp.push_back(c+'0');
        }
        if(carry)tmp.push_back(carry + '0');
        return tmp;
    }

    string multiply(string num1, string num2) {
        string res("");
        if(num1.size() == 0||num2.size() == 0)return res;
        if(num1[0] == '0'||num2[0] == '0'){
            res+='0';
            return res;
        }
        vector<string> vString;
        for(unsigned int i = 0; i < num2.size(); ++i){
            vString.push_back(multChar(num1, num2[i], num2.size() - i - 1));
            cout << vString[i] << endl;
        }
        
        int carry = 0;
        for(unsigned int i = 0; i < vString[vString.size() - 1].size(); ++i)
        {
            int sum = 0;
            for(unsigned int j = 0; j < vString.size(); ++j){
                if(i < vString[j].size())sum += vString[j][i] - '0';
            }
            sum += carry;
            if(sum > 9){
                carry = sum/10;
                sum %= 10;
            }
            else {
                carry = 0;
            }
            res.push_back(sum + '0');
        }
        if(carry)res.push_back(carry + '0');
        int length = res.size();
        for(unsigned int i = 0; i < res.size()/2; ++i){
            char tmp = res[i];
            res[i] = res[length - i - 1];
            res[length - 1 - i] = tmp;
        }
        return res;
    }
};

int main()
{
    Solution s;
    string num1("123");
    string num2("456");
    cout << s.multiply(num1, num2) <<endl;
    return 0;
}

