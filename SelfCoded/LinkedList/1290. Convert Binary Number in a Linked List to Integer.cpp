/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
