#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *createtree(int data)
{

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    return root;
}
int maxi(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
int balancefactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}
struct node *leftrotate(struct node *root)
{
    struct node *newroot = root->right;
    struct node *t = newroot->left;
    newroot->left = root;
    root->right = t;
    root->height = maxi(height(root->left), height(root->right)) + 1;
    newroot->height = maxi(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}
struct node *rightrotate(struct node *root)
{
    struct node *newroot = root->left;
    struct node *t = newroot->right;
    newroot->right = root;
    root->left = t;
    root->height = maxi(height(root->left), height(root->right)) + 1;
    newroot->height = maxi(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createtree(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    root->height = maxi(height(root->left), height(root->right)) + 1;
    int balance = balancefactor(root);
    if (balance > 1 && data < root->left->data)
    {
        return rightrotate(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return leftrotate(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void preorder(struct node *root)
{

    if (root == NULL)
    {
        return;
    }
    printf("%d-> ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d-> ", root->data);
    inorder(root->right);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);

    printf("\ninorder traversal of avl tree is\n");
    inorder(root);
    printf("\npreorder traversal of avl tree is\n");
    preorder(root);
    return 0;
}

/* #include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int maxi(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *createtree(int data)
{

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int getheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int balancefactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
}

struct node *leftrotate(struct node *root)
{
    struct node *newroot = root->right;
    struct node *t2 = newroot->left;
    newroot->left = root;
    root->right = t2;
    root->height = maxi(getheight(root->left), getheight(root->right)) + 1;
    newroot->height = maxi(getheight(newroot->left), getheight(newroot->right)) + 1;
    return newroot;
}
struct node *rightrotate(struct node *root)
{
    struct node *newroot = root->left;
    struct node *t2 = newroot->right;
    newroot->right = root;
    root->left = t2;
    root->height = maxi(getheight(root->left), getheight(root->right)) + 1;
    newroot->height = maxi(getheight(newroot->left), getheight(newroot->right)) + 1;
    return newroot;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createtree(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    root->height = 1 + maxi(getheight(root->left), getheight(root->right));
    int balance = balancefactor(root);
    if (balance > 1 && data < root->left->data) // left left case
    {
        return rightrotate(root);
    }
    if (balance < -1 && data > root->right->data) // right right case
    {
        return leftrotate(root);
    }
    if (balance > 1 && data > root->left->data) // left right case
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && data < root->right->data) // right left case
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int n, data;
    printf("enter the number of nodes you want to enter\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the data\n");
        scanf("%d", &data);
        insert(root, data);
    }
    printf("inorder traversal of tree is\n");
    inorder(root);
    return 0;
}*/