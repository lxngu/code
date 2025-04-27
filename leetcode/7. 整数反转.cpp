class Solution {
    public:
        int reverse(int x) {
            int MA=(1<<30)-1+(1<<30);
            int MI=-1<<31;
            int ans=0;
            int tmp=0;
            bool flag=0;
            while(x)
            {
                int mod = x%10; 
                if((mod<0&&(MI-mod)/10>ans))
                    return 0;
                if(mod>0&&(MA-mod)/10<ans)
                    return 0;
                ans=ans*10+mod;
                x/=10;
            }
            return ans;
        }
    };