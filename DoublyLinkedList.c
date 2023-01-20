#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE p;
    p = (NODE)malloc(sizeof(NODE));
    return p;
}

void freenode(NODE p)
{
    free(p);
}

NODE insertFront(NODE p, int ele)
{
    NODE q = getnode();
    q->data = ele;
    q->right = p;
    q->left = NULL;
    p = q;
    return p;
}

NODE deleteFront(NODE p)
{
    if (p != NULL)
    {
        int ele = p->data;
        printf("Deleted element is %d\n", ele);
        NODE q = p->right;
        q->left = NULL;
        freenode(p);
        return q;
    }
    else
    {
        printf("Deletion not possible\n");
        return NULL;
    }
}

NODE insertRear(NODE p, int ele)
{
    if (p != NULL)
    {
        NODE q = p;
        NODE prev;
        while (q->right != NULL)
        {
            prev = q;
            q = q->right;
        }
        NODE r = getnode();
        r->data = ele;
        q->right = r;
        q->left = prev;
        r->right = NULL;
        return p;
    }
    else
    {
        NODE q = getnode();
        q->right = NULL;
        q->left = NULL;
        q->data = ele;
        return p;
    }
}

NODE deleteRear(NODE p)
{
    NODE q = p;
    if (q == NULL)
    {
        return NULL;
    }
    else if (q->right == NULL && q->left == NULL)
    {
        printf("Deleted element is %d\n", q->data);
        freenode(q);
        return p;
    }
    else
    {
        while (q->right->right != NULL)
        {

            q = q->right;
        }
        NODE r = q->right;
        printf("Deleted element is %d\n", r->data);        
        q->right = NULL;
        freenode(r);
        return p;
    }
}

void display(NODE p)
{
    NODE q = p;
    while (q != NULL)
    {
        printf("%d\t", q->data);
        q = q->right;
    }
    printf("\n");
}

NODE insertPos(NODE p, int pos, int ele)
{NODE q = getnode();
        q->right = NULL;
        q->left = NULL;
        q->data = ele;
    if (p == NULL)
    {
       
        q->data = ele;
        return q;
    }
    else if (pos == 1)
    {
        p = insertFront(p, ele);
        return p;
    }
    else
    {
        NODE s = p;
        for (int i = 0; i < pos - 1; i++)
        {
            s = s->right;
            if (s->right == NULL)
            {
                printf("pos > sizeof list\n");
                p = insertRear(p, ele);
                return p;
            }
        }
        (s->left)->right = q;
        q->left = s->left;
        q->right = s;
        s->left = q;
        return p;
    }
}

NODE deletePos(NODE p, int pos)
{
    if (p == NULL)
    {
        printf("No element to be deleted\n");
        return p;
    }
    else if (pos == 1)
    {
        p = deleteFront(p);
        return p;
    }
    else
    {
        NODE prev, s;
        s = p;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = s;
            s = s->right;
            if (s == NULL)
            {
                printf("pos > sizeof list, deletion not possible\n");
                return p;
            }
            prev->right = s->right;
            s->right->left = prev;
            printf("Deleted element = %d\n", s->data);
            freenode(s);
            return p;
        }
    }
}

int search(NODE p, int ele)
{
        NODE s = p;
        int count = 0;
        while(s!=NULL)
        {
                if(s->data == ele)
                {
                        count++;
                        return count;
                }
                count++;
                s=s->right;
        }
        if(s==NULL)
                return -1;
}




void main()
{
    int a, ele, pos;
    NODE p;
    while (1)
    {
        printf("Enter 1. Insert Front\n2. Delete Front\n3.Insert Rear\n4.Delete Rear\n5. Insert position\n6. Delete position\n7.Display\n8.Search\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &ele);
            p = insertFront(p, ele);
            break;

        case 2:
            p = deleteFront(p);
            break;
        case 3:
            printf("Enter the element\n");
            scanf("%d", &ele);
            p = insertRear(p, ele);
            break;

        case 4:
            p = deleteRear(p);
            break;
        case 5:
            printf("Enter the position\n");
            scanf("%d", &pos);
            printf("Enter the element\n");
            scanf("%d", &ele);
            p = insertPos(p, pos, ele);
            break;
        case 6:
            printf("Enter the position\n");
            scanf("%d", &pos);
            p = deletePos(p, pos);
            break;
        case 7:
            display(p);
            break;
        
        case 8: printf("Enter the element\n");
            scanf("%d", &ele);
            printf("Searched element present at %d\n", search(p, ele));
            break;
        }
    }
}
