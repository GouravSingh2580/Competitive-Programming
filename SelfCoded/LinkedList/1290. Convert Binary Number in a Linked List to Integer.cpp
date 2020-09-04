class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        ListNode* tmp=head;
        int k=0;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            k++;
        }
        int sum=0;
        while(head!=NULL)
        {
            sum+=pow(2,k-1) * head->val;
            head=head->next;
            k--;
        }
    return sum;
    }
};
