#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string delSpace(const string &str){
        unsigned int i, j;
        string tmp("");
        unsigned size = str.size();
        for(i = 0; i < size && str[i] ==' '; i++);
        if(str[i] == '-' || str[i] == '+')tmp += str[i++];
        for(j = 0; i < size && str[i] >= '0' && str[i] <= '9'; j++,i++){
            tmp += str[i];
        }
        
        return tmp;
    }

    int myAtoi(string str) {
        long long res = 0;
        int flag = 1;
        string intmax("2147483647");
        string intmin("2147483648");
        string tmp("");

        str = delSpace(str);
        if(str[0] < '0'){
            flag = str[0]=='-'?-1:1;
            for(unsigned int i = 1; i < str.size(); i++)
            {
                tmp += str[i];
            }
        }
        else {
            tmp = str;
        }
       for(unsigned int j = 0; j < tmp.size(); j++){
            res = res * 10 +(tmp[j]-'0');
            if(flag == 1){
                if(res > INT32_MAX)return INT32_MAX;
            }
            else{
                if(res > 2147483648)return INT32_MIN;
            }
        }
        res *= flag;
        return res;
    }
};

int main()
{
    Solution s;
    string str("-20000000000");
    int res = s.myAtoi(str);
    cout << res << endl;
    return 0;
}

