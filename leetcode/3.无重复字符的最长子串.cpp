#include<string>
#include<map>
using namespace std;
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        map<char,int> pre;
        int ans=0;
        int cur=0;
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            char c=s[i];
            if(pre.count(c))
            {
                if(cur<=pre[c])
                {
                    ans=ans>=i-cur?ans:i-cur;
                    cur=pre[c]+1;
                }
            }
            pre[c]=i;
        }
        ans = ans>=l-cur?ans:l-cur;
        return ans;
    }
};