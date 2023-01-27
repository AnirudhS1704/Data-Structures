#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

NODE insert(NODE root, int ele)
{
    NODE temp = getnode();
    temp->data = ele;
    if (root == NULL)
        return temp;
    else
    {
        NODE p = root;
        while (1)
        {
            if (ele > p->data)
            {
                if (p->rlink == NULL)
                {
                    p->rlink = temp;
                    break;
                }
                p = p->rlink;
            }
            else
            {
                if (p->llink == NULL)
                {
                    p->llink = temp;
                    break;
                }
                p = p->llink;
            }
        }
        return root;
    }
}

void inorder(NODE root)
{
    if (root == NULL)
    {

        return;
    }
    else
    {
        inorder(root->llink);
        printf("%d\t", root->data);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if (root == NULL)
    {

        return;
    }
    printf("%d\t", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->data);
}

void main()
{
    int a, ele;
    NODE root;
    printf("Enter 1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n");
    while (1)
    {
        printf("->\t");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;

        default:
            break;
        }
    }
}


/*
Enter 1. Insert
2. Inorder
3. Preorder
4. Postorder
->	1
Enter the element
9
->	1
Enter the element
6
->	1
Enter the element
10
->	1
Enter the element
2
->	1
Enter the element
11
->	1
Enter the element
5
->	1
Enter the element
4
->	2
2	4	5	6	9	10	11	
->	3
9	6	2	5	4	10	11	
->	4
4	5	2	6	11	10	9	
->	*/
