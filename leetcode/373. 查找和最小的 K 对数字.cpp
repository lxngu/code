// #include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int sum;
    int id;
    int cur;
    bool operator<(const node &a)
    {
        return sum>a.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node> pq;
        vector<vector<int>> ans;
        int cur1=0;
        int cur2=0;
        for(int i=0;i<nums1.size();i++)
        {
            pq.push({nums1[i]+nums2[0],i,0});
        }
        for(int i=0;i<k;i++)
        {
            node cur=pq.top();
            ans.push_back({nums1[cur.id],nums2[cur.cur]});
            pq.pop();
            cur.cur+=1;
            if(cur.cur<nums2.size())
            {
                cur.sum = nums1[cur.id]+nums2[cur.cur];
                pq.push(cur);
            }
        }
        return ans;
    }
};