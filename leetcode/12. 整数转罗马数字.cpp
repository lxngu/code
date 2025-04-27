#include<string>
#include<map>
using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            int base[7]={1000,500,100,50,10,5,1};
            int chars[7]={'M','D','C','L','X','V','I'};
            string ans;
            for(int i=0;i<7;i++)
            {
                while(num>=base[i])
                {
                    ans+=chars[i];
                    num-=base[i];
                }
                int sub=i+2-(i&1);
                if(sub<7&&num>=base[i]-base[sub])
                {
                    ans+=chars[sub];
                    ans+=chars[i];
                    num-=base[i]-base[sub];
                }
            }
            return ans;
        }
    };