#include<string>
using namespace std;
class Solution {
    public:
        int myAtoi(string s) {
            long long MA=(1<<30)-1+(1<<30);
            int MI=-1<<31;
            int flag=0;
            long long ans =0;
            int sign =1;
            for(int i=0;i<s.length();i++)
            {
                if(flag==0)
                {
                    if(s[i]!=' ')
                        flag=1;
                }
                if(flag==1)
                {
                    if(s[i]=='-')
                    {
                        sign=-1;
                        i++;
                    }
                    else if(s[i]=='+')
                    {
                        sign=1;
                        i++;
                    }
                    flag=2;
                }
                if(flag==2)
                {
                    if('0'<=s[i]&& s[i]<='9')
                    {
                        int c = s[i]-'0';
                        ans=ans*10+c;
                        if(ans>MA+10)
                            break;
                    }
                    else 
                        break;
                }
            }
            ans*=sign;
            if(ans>MA)
                ans=MA;
            if(MI>ans)
                ans=MI;
            return ans;
        }       
    };