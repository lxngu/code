#include<string>
using namespace std;
class Solution {
    public:
        bool dfs(const string &s,int c_s,const string& p,int c_p)
        {
            if(c_s>=s.length()&&c_p==p.length())
                return true;
            else if(c_p>=p.length()||c_s>s.length())
                return false;
            

            if(c_p+1<p.length()&&p[c_p+1]=='*')
            {
                bool res1 = dfs(s,c_s,p,c_p+2);
                if(c_s<s.length()&&(s[c_s]==p[c_p]||p[c_p]=='.'))
                    return res1||dfs(s,c_s+1,p,c_p);
                return res1;
            }
            else
            {
                if(c_s<s.length()&&(s[c_s]==p[c_p]||p[c_p]=='.'))
                    return dfs(s,c_s+1,p,c_p+1);
                return false;
            }
        }
        string update(string p)
        {
            string up=p;
            int cur=0;
            for(int i=0;i<p.length();i++)
            {
                
                if(i+1<p.length()&&p[i+1]=='*')
                {
                    if(cur>1&&up[cur-1]=='*'&&(up[cur-2]==p[i]||p[i]=='.'))
                    {
                        cur-=2;
                    }
                    up[cur]=p[i];
                    up[cur+1]=p[i+1];
                    cur+=2;
                    i++;
                }
                else
                {
                    up[cur++]=p[i];
                }
            }
            string f;
            for(int i=0;i<cur;i++)
                f+=up[i];
            return f;
        }
        bool isMatch(string s, string p) {
            p=update(p);
            return dfs(s,0,p,0);
        }
    };