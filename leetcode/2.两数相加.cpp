struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        int c = 0;
        while(l1!=nullptr||l2!=nullptr||c!=0)
        {
            int a,b;
            a=b=0;
            if(l1!=nullptr)
            {
                a=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr)
            {
                b=l2->val;
                l2=l2->next;
            }    
            int sum = a+b+c;
            cur->val = sum%10;
            c = sum/10;
            if(c != 0||l1!=nullptr||l2!=nullptr)
            {
                ListNode *nxt = new ListNode();
                cur->next = nxt;
                cur=nxt;

            }
        }
        return ans;
    }
};