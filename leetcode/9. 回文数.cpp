#include<string>
using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0)
                return false;
            long long num =0;
            long long tmp=x;
            while(x)
            {
                num*=10;
                num+=x%10;
                x/=10;
            }
            return num==tmp;
        }
    };