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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

if(head->next==NULL){return head;}
if(head==NULL){return NULL;}
 ListNode* dummy=head;
  ListNode* leftprev=head;
int cnt=1;
while(cnt < left-1){
leftprev=leftprev->next;
cnt++;
}
  ListNode* curr= leftprev->next;
    ListNode*forward=NULL;
      ListNode*prev=NULL;
      int cnt2=0;
while(cnt2<right-left+1 && curr!=NULL){
forward=curr->next;
curr->next=prev;
prev =curr;
curr=forward;

    cnt2++;
}

 dummy->next=prev;

 return dummy;

    }
};


