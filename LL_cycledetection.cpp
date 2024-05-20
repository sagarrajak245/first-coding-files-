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

node *floydscycle(node *&head)
{

    if (head == NULL)
    {
        return NULL; // true
    }

    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {

        fast = fast->next;

        slow = slow->next;
        if (slow == fast)
        {
            // cout << "the loop is at" << slow->data;
            return slow; // true
        }
    }

    return NULL; // false
}

node *getnode(node *&head)
{

    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floydscycle(head);
    node *slow = head;
    while (slow != intersection)
    {

        slow = slow->next;
        intersection = intersection->next;

        if (slow == intersection)
        {
            return slow;
        }
    }

    return NULL;
}
// remove loop in linked list

void remove_loop(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    node *startofloop = getnode(head);

    node *temp = startofloop;
    while (temp->next != startofloop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{

    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;
    /* insertathead(node1, 12);
     insertathead(node1, 13);
     insertathead(node1, 14);
     insertathead(node1, 15);*/

    inserttail(tail, 100);

    inserttail(tail, 11);

    insertatmiddle(tail, head, 4, 20);

    inserttail(tail, 200);
    print(head);
    // cout << tail->next; // null update ho chuka hai....
    cout << endl;
    cout << endl;
    /* deletetion(3, head);
     print(head);
     cout << endl;
     cout << endl;*/

    tail->next = head->next;

    if (detect(head))
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    node *ans = getnode(head);
    cout << "the starting node of loop is  " << ans->data << endl;

    remove_loop(head);
    cout << " the list after removal of loop is" << endl;
    print(head);

    return 0;
}