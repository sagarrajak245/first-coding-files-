#include <iostream>
#include <list>

using namespace std;

// delete kth node from end of linked list
/*
class Solution
{

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        int k = cnt - n;
        int pos = 1;

        ListNode *curr = head;

        ListNode *prev = NULL;

        while (pos < k)
        {

            prev = curr;
            curr = curr->next;
            pos++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;
    }
};
*/
// sagar's code
// space complexity O(1)
// time complexity O(2n)// 2 traversal
// edge case when n is equal to length of linked list

int main()
{

    return 0;
}