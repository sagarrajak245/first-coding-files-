
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare
{
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();

        if (k == 0)
            return NULL;

        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        // Push the heads of all lists into the priority queue
        for (int i = 0; i < k; ++i)
        {
            if (lists[i] != NULL)
            {
                pq.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        // Merge step
        while (!pq.empty())
        {
            ListNode *top = pq.top();
            pq.pop();

            // Append the top node to the merged list
            if (head == NULL)
            {
                head = top;
                tail = top;
            }
            else
            {
                tail->next = top;
                tail = tail->next;
            }

            // Push the next node of the top node into the priority queue
            if (top->next != NULL)
            {
                pq.push(top->next);
            }
        }

        return head;
    }
};

int main()
{
    vector<ListNode *> lists;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);

    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    Solution obj;
    ListNode *result = obj.mergeKLists(lists);

    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
