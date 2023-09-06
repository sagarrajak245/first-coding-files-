
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *link; // next
};

struct Node *start = NULL;

struct Node *GetNode()
{
    return ((struct Node *)malloc(sizeof(struct Node)));
}

void CreateList();
int CountNodes();
void Insert();
void InsertBefore();
void InsertAfter();
void InsertAtPosition();
void Delete();
void DeleteByValue();
void DeleteAtPosition();
void Display();

int main()
{
    int ch;

    do
    {

        printf("\n\n********** CHOICES *********");
        printf("\n\n1 : CREATE LIST");
        printf("\n2 : INSERT A NODE");
        printf("\n3 : DELETE A NODE");
        printf("\n4 : DISPLAY LIST");
        printf("\n5 : EXIT");
        printf("\n\nENTER YOUR CHOICE : \t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // create list
        {
            CreateList();
            printf("\n\nNODES PRESENT : %d", CountNodes());
        }
        break;

        case 2: // insert node
        {
            Insert();
        }
        break;

        case 3: // delete node
        {
            Delete();
        }
        break;

        case 4: // display list
        {
            Display();
        }
        break;

        case 5: // exit
            break;

        default:
            printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
        }
        // getch();
    } while (ch != 5);
}

void CreateList()
{
    struct Node *end = NULL, *temp;
    char ch;
    if (start != NULL)
    {
        printf("\n\nTHE LIST IS ALREADY CREATED !!");
        return;
    }
    do
    {
        temp = GetNode();
        printf("\n\nENTER THE DATA TO BE INSERTED : \t");
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (start == NULL) // first node is created hence start is pointing  towards newly created node(ie. temp)
        {
            start = temp;
        }
        else
        {
            end->link = temp;
        }
        end = temp; // change position then observe it
        printf("\nDO YOU WANT TO CONTINUE (Y/N) ... ");
        ch = getche();
    } while (ch == 'Y' || ch == 'y');
}
void Insert()
{
    int ch;
    // we can check here - if the list is existing
    do
    {
        // clrscr();

        printf("\n\n******* INSERT OPTIONS *******");
        printf("\n\n1 : INSERT BEFORE A NODE");
        printf("\n2 : INSERT AFTER A NODE");
        printf("\n3 : INSERT AT A POSITION");
        printf("\n4 : DISPLAY");
        printf("\n5 : BACK TO MAIN MENU");
        printf("\n\nENTER YOUR CHOICE : \t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // INSERT BEFORE
        {
            InsertBefore();
        }
        break;

        case 2: // insert after a node
        {
            InsertAfter();
        }
        break;

        case 3: // insert at a position
        {
            InsertAtPosition();
        }
        break;

        case 4: // display list
        {
            Display();
        }
        break;

        case 5: // BACK TO MAIN MENU
            return;
            // break;

        default:
            printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
        }
        // getch();
    } while (1); // while(ch!=5);
}
void InsertBefore()
{
    int val;
    struct Node *ptrAtValue;
    struct Node *I;
    struct Node *ptrBeforeValue;
    if (start == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }
    printf("\n\nENTER THE DATA BEFORE WHICH NEW NODE TO BE INSERTED : \t");
    scanf("%d", &val);

    ptrAtValue = start;
    /*
    while( ptrAtValue!=NULL && (ptrAtValue->data != val))
    {
        printf("\nVisited %d",ptrAtValue->data);
        ptrAtValue = ptrAtValue->link;
    }*/

    while (ptrAtValue->data != val)
    {
        printf("\nVisited %d", ptrAtValue->data);
        ptrAtValue = ptrAtValue->link;
        if (ptrAtValue == NULL)
        {
            printf("Not Found ");
            return;
        }
    }
    // printf("here");
    if (ptrAtValue == NULL)
    {
        printf("\n\nREQUIRED NODE NOT FOUND !!!");
        return;
    }

    I = GetNode();
    printf("\n\nENTER THE DATA TO BE INSERTED : \t");
    scanf("%d", &I->data);

    if (ptrAtValue == start) // INSERT BEFORE FIRST
    {
        I->link = start;
        start = I;
    }
    else
    {
        ptrBeforeValue = start;
        while (ptrBeforeValue->link != ptrAtValue)
        {
            ptrBeforeValue = ptrBeforeValue->link;
        }
        ptrBeforeValue->link = I;
        I->link = ptrAtValue;
    }
}

void InsertAfter()
{
    int val;
    struct Node *ptrAtValue;
    struct Node *I;
    if (start == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }

    printf("\n\nENTER THE DATA AFTER WHICH NEW NODE TO BE INSERTED : \t");
    scanf("%d", &val);

    ptrAtValue = start;

    while (ptrAtValue->data != val)
    {
        // printf("\nVisited %d",ptrAtValue->data);
        ptrAtValue = ptrAtValue->link;
        if (ptrAtValue == NULL)
        {
            printf("Not Found ");
            return;
        }
    }

    I = GetNode();
    printf("\n\nENTER THE DATA TO BE INSERTED : \t");
    scanf("%d", &I->data);
    // following code will work
    // for any node , even the last node
    I->link = ptrAtValue->link;
    ptrAtValue->link = I;
}

void InsertAtPosition()
{
    int pos, nodeCount, i;
    struct Node *ptrBeforePos;
    struct Node *I;
    if (start == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }
    nodeCount = CountNodes();
    printf("\n\nNODES PRESENT IN LIST : %d", nodeCount);
    printf("\n\nENTER A VALUE BETWEEN %d & %d", 1, nodeCount + 1);

    // while(1)
    //{
    printf("\n\nENTER POSITION AT WHICH NEW NODE TO BE INSERTED : \t");
    scanf("%d", &pos);
    if (pos < 1 || pos > nodeCount + 1)
    {
        printf("\n\nINVALID VALUE !");
        return;
        /*
        Display();
        printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
        printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount+1);
        continue;*/
    }
    // break;
    //}
    I = GetNode();
    printf("\n\nENTER THE DATA TO BE INSERTED : \t");
    scanf("%d", &I->data);

    if (pos == 1) // insert before start
    {
        I->link = start;
        start = I;
        return;
    }
    ptrBeforePos = start;

    for (i = 0; i < pos - 2; i++)
        ptrBeforePos = ptrBeforePos->link;

    I->link = ptrBeforePos->link;
    ptrBeforePos->link = I;
}
int CountNodes()
{
    struct Node *temp = start;
    int count = 0;
    if (temp == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return 0;
    }
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}
void Delete()
{
    int ch;
    do
    {
        // clrscr();
        //  we can check here - if list is existing
        printf("\n\n******* DELETE OPTIONS *******");
        printf("\n\n1 : DELETE NODE BY VALUE");
        printf("\n2 : DELETE NODE AT A POSITION");
        printf("\n3 : DISPLAY");
        printf("\n4 : BACK TO MAIN MENU");
        printf("\n\nENTER YOUR CHOICE : \t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1: // DELETE BY VALUE
        {
            DeleteByValue();
        }
        break;

        case 2: // delete node at a position
        {
            DeleteAtPosition();
        }
        break;

        case 3: // display
        {
            Display();
        }
        break;

        case 4: // BACK TO MAIN MENU
            return;
            // break;

        default:
            printf("\n\nWRONG ENTRY ! TRY AGAIN ...");
        }
        getch();
    } while (1); // while(ch!=4);
}
void DeleteByValue()
{
    int val;
    struct Node *ptrAtValue;
    struct Node *ptrBeforeValue;
    if (start == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }
    printf("\n\nENTER THE DATA OF NODE TO BE DELETED : \t");
    scanf("%d", &val);

    ptrAtValue = start;

    while ((ptrAtValue->data != val) && ptrAtValue != NULL)
        ptrAtValue = ptrAtValue->link;

    if (ptrAtValue == NULL)
    {
        printf("\n\nREQUIRED NODE NOT FOUND !!!");
        return;
    }

    if (ptrAtValue == start) // DELETE FIRST NODE
    {
        start = start->link;
        // ptrAtValue -> link = NULL;
        // free(ptrAtValue);
    }
    else
    {
        ptrBeforeValue = start;
        while (ptrBeforeValue->link != ptrAtValue)
            ptrBeforeValue = ptrBeforeValue->link;
        ptrBeforeValue->link = ptrAtValue->link;
        // ptrAtValue -> link = NULL;
        // free(ptrAtValue);
    }
    printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.", ptrAtValue->data);
    ptrAtValue->link = NULL;
    free(ptrAtValue);
}

void DeleteAtPosition()
{
    int pos, nodeCount, i;
    struct Node *ptrBeforePos, *ptrAtPos;
    if (start == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }
    nodeCount = CountNodes();
    printf("\n\nNODES PRESENT IN LIST : %d", nodeCount);
    printf("\n\nENTER A VALUE BETWEEN %d & %d", 1, nodeCount);

    // while(1)
    //{
    printf("\n\nENTER POSITION OF NODE TO BE DELETED : \t");
    scanf("%d", &pos);
    if (pos < 1 || pos > nodeCount)
    {
        printf("\n\nINVALID VALUE !");
        return;
        /*
        Display();
        printf("\n\nNODES PRESENT IN LIST : %d",nodeCount);
        printf("\n\nENTER A VALUE BETWEEN %d & %d",1,nodeCount+1);
        continue;*/
    }
    // break;
    //}

    if (pos == 1)
    {
        ptrAtPos = start;
        start = start->link;
        // ptrAtPos->link = NULL;
        // printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtPos->data);
        // free(ptrAtPos);
    }
    else
    {
        ptrBeforePos = start;

        for (i = 0; i < pos - 2; i++)
            ptrBeforePos = ptrBeforePos->link;
        ptrAtPos = ptrBeforePos->link; // the node to be deleted
        ptrBeforePos->link = ptrAtPos->link;
        // printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.",ptrAtPos->data);
        // ptrAtPos->link = NULL;
        // free(ptrAtPos);
    }
    printf("\n\nTHE NODE HAVING DATA  %d IS DELETED.", ptrAtPos->data);
    ptrAtPos->link = NULL;
    free(ptrAtPos);
}
void Display()
{
    struct Node *temp = start;
    if (temp == NULL)
    {
        printf("\n\nLIST IS EMPTY !!!");
        return;
    }
    printf("\n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->link != NULL)
            printf(" -> ");
        temp = temp->link;
    }
}