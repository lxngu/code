#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
            map<int,int> mp;
            for(int i=0;i<pieces.size();i++)
                mp[pieces[i][0]]=i;
                
            for(int i=0;i<arr.size();)
            {
                bool flag=0;
                if(mp.count(arr[i]))
                {
                    for(auto a:pieces[mp[arr[i]]])
                    {
                        if(a!=arr[i])
                            return false;
                        i++;
                    }
                }
                else
                    return false;
            }
            return true;
        }
    };