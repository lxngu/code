#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
        string convert(string s, int numRows) {
            int l = s.length();
            string ans;
            if(numRows==1)
                return s;
            for(int i=0;i<numRows;i++)
            {
                int cur = i;
                int mid = (numRows-1)*2-i;
                while(cur<s.length())
                {
                    ans+=s[cur];
                    if(i!=0&&i+1!=numRows)
                    {
                        if(mid<s.length())
                            ans+=s[mid];
                        mid+=numRows*2-2;
                    }
                    cur+=numRows*2-2;
                }
            }
            return ans;
        }
    };