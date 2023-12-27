#include <iostream>
#include <vector>
using namespace std;

// basic of linked list,,,,,,

class node
{

public:
    int data;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor bcoz we are using dynamic memory
    ~node()
    {

        if (this->next != NULL)
        {

            delete next;
            this->next = NULL;
        }
    }
};

void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void inserttail(node *&tail, int d)
{
    node *temp = new node(d);

    tail->next = temp;
    tail = temp;
}

void insertatmiddle(node *&tail, node *&head, int position, int data)
{
    node *temp = head;
    int cnt = 1;

    if (position == 1)
    {

        insertathead(head, data);
        return;
    }

    while (cnt < position - 1)
    {
        cnt++;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        inserttail(tail, data);
        return;
    }
    node *nodetoinsert = new node(data);

    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deletetion(int position, node *&head)
{

    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    // for all middle and last position deletetion

    else
    {
        node *curr = head;
        node *prev = NULL; // ye ek empty node hai jo sirf desire node tak pahuchne ke liye banya tha
        int cnt = 1;
        while (cnt < position)
        {

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;

        temp = temp->next;
    }
}

bool checkpallindrome(vector<int> an)
{

    int start = 0;
    int end = an.size() - 1;
    while (start <= end)
    {
        if (an[start++] == an[end--])
        {
            // start++;
            // end--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool llpallindrome(node *&head)
{

    vector<int> an;
    if (head == NULL || head->next->next == NULL)
    {
        return true;
    }

    node *temp = head;
    while (temp != NULL)
    {

        an.push_back(temp->data);

        temp = temp->next;
    }
    return checkpallindrome(an);
}
node *getmid(node *head)
{
    if (head == NULL || head->next->next == NULL)
    {
        return head;
    }

    node *fast = head->next;
    node *slow = head;
    while (fast != NULL && fast->next != NULL && slow != NULL)
    {

        fast = fast->next;

        slow = slow->next;
    }
    return slow;
}

node *rev(node *&head)
{

    if (head == NULL || head->next->next == NULL)
    {
        return head;
    }

    node *prev = NULL;
    node *forward = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// 2method for pallindrome checking; //code not working...
bool lllpallindrome(node *&head)
{

    if (head == NULL || head->next->next == NULL)
    {
        return true;
    }

    node *middle = getmid(head);
    node *temp = middle->next;
    middle->next = rev(temp);

    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }

        head1 = head1->next;
        head2 = head2->next;
    }
    // temp = middle->next;
    // middle->next = rev(temp); // backtracking;

    return true;
}
int main()
{

    node *node1 = new node(1);
    node *tail = node1;
    node *head = node1;

    inserttail(tail, 2);

    inserttail(tail, 3);

    insertatmiddle(tail, head, 4, 3);

    inserttail(tail, 2);
    inserttail(tail, 1);
    print(head);

    cout << endl;
    cout << endl;
    /* if (llpallindrome(node1))
     {

         cout << "the given ll is pallindrome" << endl;
     }
     else
     {
         cout << "the given ll is not pallindrome" << endl;
     }
 */
    if (lllpallindrome(node1))
    {

        cout << "the given llll is pallindrome" << endl;
    }
    else
    {
        cout << "the given llll is not pallindrome" << endl;
    }

    return 0;
}