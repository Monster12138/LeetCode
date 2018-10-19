#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class Solution {
public:
    bool Cmp(string str, string substr)
    {
        char str1[1000];
        char str2[1000];

        strcpy(str1,str.c_str());
        strcpy(str2,substr.c_str());
        if(strstr(str1,str2)!=NULL)return true;
        else return false;
    }

    string Reverse(string str)
    {
        unsigned int length = str.size();
        string res(str);
        for(unsigned int i = 0 ;i < str.size();i++, length--)
        {
            res[i] = str[length - 1];
        }
        return res;
    }

    string longestPalindrome(string s) {
        unsigned int slength = s.size();
        if(slength <= 1)return s;
/*        do{
            string SubString(s);
            SubString = Reverse(SubString);
            unsigned int Sublength = SubString.size();
            while(--Sublength){
                SubString.pop_back();
                if(Cmp(s,SubString))return SubString;
            }
            for(unsigned int i = 0;i < slength - 1; i++){
                s[i] = s[i+1];
            }
            s.pop_back();
            slength--;
        }
        */ 
        string SubString(s);
        string tmp2(s);
        unsigned int tlength = tmp2.size();
        while(--tlength)
        { 
            cout<<"tmp2:>"<<tmp2<<endl;
            slength = tmp2.size();
            string tmp1(tmp2);
            while(--slength > 1){
                SubString = tmp1;
                SubString.pop_back();
                tmp1.pop_back();
                SubString = Reverse(SubString);
                cout<<SubString<<endl;
                if(Cmp(s,SubString))return SubString;
            }
            for(unsigned int i = 0;i < slength - 1; i++){
                tmp2[i] = tmp2[i+1];
            }
            tmp2.pop_back();
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string str("cbbd");
    string res = s.longestPalindrome(str);
    cout<< res <<endl;
    return 0;
}

