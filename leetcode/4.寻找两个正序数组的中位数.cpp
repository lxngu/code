#include<vector>
#include<iostream>
using namespace std;


class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.size()>nums2.size())
                swap(nums1,nums2);
            int m,n;
            m=nums1.size();
            n=nums2.size();
            int l,r;
            l=0;
            r=m;
            int M=1e9;
            int l1,l2,r1,r2;
            while(l<r)
            {
                int mid1 = l+r+1>>1;
                int mid2 = (m+n)/2-mid1;
                
                l1=mid1==0?-M:nums1[mid1-1];
                r1=mid1==m?M:nums1[mid1];
                l2=mid2==0?-M:nums2[mid2-1];
                r2=mid2==n?M:nums2[mid2];
                if(l1<=r2)
                    l=mid1;
                else
                    r=mid1-1;
            }
            int mid1 = l+r+1>>1;
            int mid2 = (m+n)/2-mid1;
            
            l1=mid1==0?-M:nums1[mid1-1];
            r1=mid1==m?M:nums1[mid1];
            l2=mid2==0?-M:nums2[mid2-1];
            r2=mid2==n?M:nums2[mid2];
            return m+n&1?min(r1,r2):(max(l1,l2)+min(r1,r2))/2.0;
        }
    };

int main(void)
{
    cout<<"hello";
    cout<<">>";
    return 0;
}