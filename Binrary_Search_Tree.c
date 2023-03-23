#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node *NODE;

NODE getnode(int ele)
{
    NODE p = (NODE)malloc(sizeof(NODE));
    p->data = ele;
    p->right = NULL;
    p->left = NULL;
    return p;
}

NODE insert(NODE p, int ele)
{
    NODE r = getnode(ele);
    NODE curr = p;
    if (p == NULL)
    {
        return r;
    }
    while (1)
    {
        if (ele > curr->data)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = r;
                break;
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = r;
                break;
            }
        }
    }
    return p;
}

void inorder(NODE p)
{
    NODE q = p;
    if (q == NULL)
        return;
    inorder(q->left);
    printf("%d\t", q->data);
    inorder(p->right);
}

void preorder(NODE p)
{
    NODE q = p;
    if (q == NULL)
        return;
    printf("%d\t", q->data);
    preorder(q->left);
    preorder(q->right);
}

void postorder(NODE p)
{
    NODE q = p;
    if (q == NULL)
        return;
    postorder(q->left);
    postorder(q->right);
    printf("%d\t", q->data);
}

void main()
{
    NODE p;
    int ele, n;
    printf("Enter 1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n");
    while (1)
    {
        printf("->\t");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter number to insert\n");
            scanf("%d", &ele);
            p = insert(p, ele);
            break;
        case 2:
            inorder(p);
            break;
        case 3:
            preorder(p);
            break;
        case 4:
            postorder(p);
            break;

        default:
            break;
        }
    }
}
