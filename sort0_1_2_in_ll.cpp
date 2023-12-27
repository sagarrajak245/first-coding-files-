#include <iostream>
#include <list>
#include <map>
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
// detection of loop in linked list 1 method;
bool detect(node *&head)
{
    if (head == NULL)
    {
        return false;
    }

    node *temp = head;
    map<node *, bool> visited;

    while (temp != NULL)
    {

        if (visited[temp] == true)
        {
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// floyds cycle for loop detection;

bool floydscycle(node *&head)
{

    if (head == NULL)
    {
        return false;
    }

    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

node *sorting(node *&head)
{

    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (zerocount != 0)
        {

            temp->data = 0;
            zerocount--;
        }

        else if (onecount != 0)
        {

            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {

            temp->data = 2;
            twocount--;
        }

        temp = temp->next;
    }

    return temp;
}
// 2 method for sorting 0 and 1 .....first make zero,one .two ki dummy node....second step copy that 0,1,2 in respective nodes then
// 3 step merge them by pointing perfectly remember one edge case where middle node might be empty..

int main()
{

    node *node1 = new node(1);
    node *tail = node1;
    node *head = node1;

    inserttail(tail, 1);

    inserttail(tail, 0);

    insertatmiddle(tail, head, 4, 0);

    inserttail(tail, 2);
    print(head);

    cout << endl;
    cout << endl;
    sorting(node1);
    cout << "the ll after sorting is" << endl;
    print(head);
    return 0;
}