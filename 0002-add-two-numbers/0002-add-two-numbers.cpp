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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l1;
        ListNode* temp2=l2;
        int carry=0;
        ListNode* prev = new ListNode(-1);
        ListNode* dummy = prev;
        int valu=0;
        while(temp!=NULL && temp2!=NULL){
            valu = temp->val + temp2->val;
            if(carry!=0){
                valu+=carry;
            }
            if(valu >= 10)
            {
                carry= valu/10;
            }
            else{
                carry = 0;
            }
            valu = valu % 10;
            prev->next = new ListNode(valu);
            prev = prev->next;
            temp=temp->next;
            temp2=temp2->next;
        }
        while(temp!=NULL){
            valu= temp -> val;
            if(carry != 0){
                valu += carry;
                carry = 0;
            }
            if(valu >=10){
                carry= (valu % 10) + 1;
                valu = valu % 10;
            }
            prev->next= new ListNode(valu);
            prev=prev->next;
            temp=temp->next;
        }
        while(temp2!=NULL){
            valu= temp2 -> val;
            if(carry != 0){
                valu += carry;
                carry = 0;
            }
            if(valu >=10){
                carry= (valu % 10) + 1;
                valu = valu % 10;
            }
            prev->next = new ListNode(valu);
            prev = prev->next;
            temp2=temp2->next;
        }
        if(carry!=0){
            prev->next = new ListNode(carry);
            prev = prev->next;
        }
        return dummy->next;
    }
};