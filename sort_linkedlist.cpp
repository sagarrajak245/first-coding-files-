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

// sorted linked list duplicate removal

void duplicate(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {

        if (curr->data == curr->next->data)
        {
            node *next_next = curr->next->next; // ye  method tab use hota hai jab without position and data deletion perform karna pade..
            node *next_to_delete = curr->next;
            delete next_to_delete;
            curr->next = next_next;
        }

        else
        {
            curr = curr->next;
        }
    }

    return;
}

int main()
{

    node *node1 = new node(10);
    node *tail = node1;
    node *head = node1;

    inserttail(tail, 20);

    inserttail(tail, 30);

    insertatmiddle(tail, head, 4, 30);

    inserttail(tail, 40);
    inserttail(tail, 50);
    inserttail(tail, 50);
    print(head);

    cout << endl;
    cout << endl;

    duplicate(head);

    cout << "after removal of duplicate ll is " << endl;
    print(head);

    return 0;
}