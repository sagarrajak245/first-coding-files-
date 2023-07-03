#include <iostream>
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

        if (next != NULL)
        {

            delete next;
            next = NULL;
        }
    }
};
// circular me koi start and end ka pata nahi rahata..
// isliye koi head and tail ka actual meaning nahi hai but apne convinient ke liye tail use karna better hai

void insertatnode(node *&tail, int element, int data)
{

    // isme 2 cases bante hai mostly eighter list is empty
    // eighter list contains elements

    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        temp->next = temp;
    }

    // list empty nahi hai element present hai list me
    // pahle search for element
    else
    {

        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletition(node *&tail, int element)
{

    // if list is empty
    if (tail == NULL)
    {
        cout << "the list is empty";
        return;
    }

    else
    {

        node *prev = tail;
        node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&tail)
{

    node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
    cout << endl;
}
// to check circular linked list;
bool iscircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

int main()
{

    node *tail = NULL;
    insertatnode(tail, 5, 3);
    print(tail);
    insertatnode(tail, 3, 7);
    print(tail);
    insertatnode(tail, 7, 8);
    print(tail);
    insertatnode(tail, 8, 10);
    print(tail);
    cout << endl
         << endl;

    if (iscircular(tail))
    {
        cout << "it is circular linked list" << endl;
    }
    else
    {
        cout << "it is not circular linked list" << endl;
    }

    return 0;
}