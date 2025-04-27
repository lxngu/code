#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        int extend(int mid,int len,const string &s)
        {
            int left=mid-len;
            int right=mid+len;
            while(left>0&&right<s.length()-1&&s[left-1]==s[right+1])
            {
                left--;
                right++;
            }
            return (right-left)/2;
        }
        string longestPalindrome(string s) {
            string str;
            string ans;
            str+=s[0];
            for(int i=1;i<s.length();i++)
            {
                str+='*';
                str+=s[i];
            }
            vector<int> arm_len(str.length(),0);
            int j=-1;
            int right=-1;
            int mxl=0;
            int length=0;
            int id = -1;
            for(int i=0;i<str.size();i++)
            {
                int cur_arm;
                if(right>=i)
                {
                    cur_arm = min(arm_len[j*2-i],right-i);
                    cur_arm = extend(i,cur_arm,str);
                }
                else
                {
                    cur_arm=extend(i,0,str);
                }
                arm_len[i]=cur_arm;
                if(i+cur_arm>right)
                {
                    right = i+cur_arm;
                    j=i;
                }

                int len=(cur_arm+(i&1))/2*2+(!(i&1));
                if(mxl<len)
                {
                    mxl=len;
                    id=i;
                    length=cur_arm;
                }


            }
            

            for(int i=id-length;i<=id+length;i++)
            {
                if(str[i]!='*')
                    ans+=str[i];
            }
            return ans;
        }
    };