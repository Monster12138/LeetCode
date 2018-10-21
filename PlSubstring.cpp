#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class Solution {
public:
    bool Is_SubString(string str)
    {
        int i = 0;
        int length = str.size() - 1;
        while(i < length)
        {
            if(str[i] != str[length])return false;
            i++;
            length--;
        }

        return true;
    }


    string Cut(const char *str, int n)
    {
        string tmp = "";
        for(int i = 0;i < n; i++)
        {
            tmp += str[i];
        }

        return tmp;
    }

/*    string longestPalindrome(string s) {
        unsigned int slength = s.size();
        if(slength <= 1)return s;

        unsigned int n = slength;
        while(n > 0)
        {
            for(unsigned int i = 0; i + n <= slength; i++){
                string str1 = Cut(s.c_str()+i, n);
                if(Is_SubString(str1)){
                    return str1;
                }
            }
            n--;
        }
        s = Cut(s.c_str(),1);
       return s;
    }*/

    string GetSubString(string s, unsigned int left, unsigned int& index)
    {
        string tmp("");
        unsigned int i;
        for(i = left;i>=0 && s[i] == s[i+index];i--){
            index += 2;
        }

        for(unsigned int j = 0; j <= index; j++)
        {
            tmp += s[++i];
        }

        return tmp;
    }

    string longestPalindrome(string s) {
        unsigned int slength = s.size();
        if(slength <= 1)return s;

        string MaxSubString("");
        for(unsigned int i = 0; i + 2< slength; i++){
            if(s[i] == s[i+2]){
                unsigned int index = 2;
                string tmp = GetSubString(s, i, index);
                if(MaxSubString.size() < tmp.size()){
                    MaxSubString = tmp;
                }
            }
        }
        if(MaxSubString == ""){

        }
        return MaxSubString;
    }

};

int main()
{
    Solution s;
    string str("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy");
    string res = s.longestPalindrome(str);
    cout<< res <<endl;
    return 0;
}

