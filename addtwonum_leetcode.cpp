#include <iostream>
using namespace std;

// basic of linked list,,,,,,
// node ek block hai jo sirf ek part me data and other part me addressstore karta hai....
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
// 1st method--- recursive solution for reversing linked list........
node *rev(node *&head)
{

    // base case..
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *shead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

// 2 nd method--- iterative approach...
node *rev2(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

node *add_list(node *l1, node *l2)
{

    node *temp1 = rev2(l1);
    node *temp2 = rev2(l2);
    node *temp3 = new node(-1);
    node *tail = NULL;
    node *head = NULL;

    int carry = 0;
    int sum = 0;
    while (temp1 != NULL && temp2 != NULL)
    {

        sum = temp1->data + temp2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        if (tail == NULL)
        {
            temp3 = new node(sum);
            tail = temp3;
        }
        else
        {
            node *temp3 = new node(sum);
            tail->next = temp3;
            tail = temp3;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        sum = temp1->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        node *temp3 = new node(sum);
        tail->next = temp3;
        tail = temp3;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        sum = temp2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        node *temp3 = new node(sum);
        tail->next = temp3;
        tail = temp3;
        temp2 = temp2->next;
    }
    if (carry != 0)
    {
        node *temp3 = new node(carry);
        tail->next = temp3;
        tail = temp3;
    }
    temp3 = rev2(temp3);
    return temp3;
}

int main()
{

    node l1 = node(1);
    node *head1 = &l1;

    insertathead(head1, 5);
    insertathead(head1, 4);

    node l2 = node(1);
    node *head2 = &l2;

    insertathead(head2, 2);
    insertathead(head2, 9);

    cout << "sum is" << endl;
    node *head3 = add_list(head1, head2);
    print(head3);

    return 0;
}