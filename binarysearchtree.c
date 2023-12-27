#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                 // node will store some data
    struct node *right_child; // right child
    struct node *left_child;  // left child
};

// function to create a node
struct node *newnode(int x)
{
    struct node *temp;
    temp = malloc(sizeof(struct node)); // allocating memory to the node  using malloc
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;

    return temp;
}

// searching operation
struct node *search(struct node *root, int x)
{
    if (root == NULL || root->data == x) // if root->data is x then the element is found
        return root;
    else if (x > root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else // x is smaller than the data, so we will search the left subtree
        return search(root->left_child, x);
}

// insertion
struct node *insert(struct node *root, int x)
{
    // searching for the place to insert
    if (root == NULL)
        return newnode(x);
    else if (x > root->data) // x is greater. Should be inserted to the right
        root->right_child = insert(root->right_child, x);
    else // x is smaller and should be inserted to left
        root->left_child = insert(root->left_child, x);
    return root;
}

// function to find the minimum value in a node
struct node *sucessor(struct node *root)
{
    if (root == NULL)
        return NULL;
    else if (root->left_child != NULL)     // node with minimum value will have no left child
        return sucessor(root->left_child); // left most element will be minimum
    return root;
}

// deletion
struct node *delete(struct node *root, int x)
{
    // searching for the item to be deleted
    if (root == NULL)
        return NULL; // root is null
    if (x > root->data)
        root->right_child = delete (root->right_child, x);
    else if (x < root->data)
        root->left_child = delete (root->left_child, x);
    else
    {
        // No Child node means leaf node
        if (root->left_child == NULL && root->right_child == NULL)
        {
            free(root);
            return NULL;
        }

        // One Child node
        else if (root->left_child == NULL || root->right_child == NULL)
        {
            struct node *temp;
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        // Two Children
        else
        {
            struct node *temp = sucessor(root->right_child);
            root->data = temp->data;
            root->right_child = delete (root->right_child, temp->data);
        }
    }
    return root;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root == NULL) // checking if the root is not null
    {
        return;
    }
    inorder(root->left_child);   // traversing left child
    printf(" %d->", root->data); // printing data at root
    inorder(root->right_child);  // traversing right child
}

void postorder(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    postorder(root->left_child);
    postorder(root->right_child);
    printf("%d-> ", root->data);
}

void preorder(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    printf("%d-> ", root->data);
    preorder(root->left_child);
    preorder(root->right_child);
}

void levelorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear] = root;
    rear++;
    while (front < rear)
    {
        struct node *temp = queue[front];
        printf("%d-> ", temp->data);
        front++;
        if (temp->left_child)
        {
            queue[rear] = temp->left_child;
            rear++;
        }
        if (temp->right_child)
        {
            queue[rear] = temp->right_child;
            rear++;
        }
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left_child);
    int right_height = height(root->right_child);
    if (left_height > right_height)
    {
        return left_height + 1;
    }
    else
    {
        return right_height + 1;
    }
}

int main()
{
    struct node *root;
    root = newnode(20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);
    printf("after inorder call\n");
    inorder(root);
    printf("\n");

    root = delete (root, 1);

    root = delete (root, 40);

    root = delete (root, 45);

    root = delete (root, 9);
    printf("after deletition call\n");
    inorder(root);
    printf("\n");

    printf("after preorder call\n");
    preorder(root);
    printf("\n");

    printf("after postorder call\n");
    postorder(root);
    printf("\n");

    printf("after levelorder call\n");
    levelorder(root);
    printf("\n");

    struct node *temp = search(root, 20);

    if (temp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found\n");
    }

    root = delete (root, 7);
    printf("after levelorder call\n");
    levelorder(root);
    printf("\n");

    int h = height(root);
    printf("height of the tree is %d\n", h);

    return 0;
}
