#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
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
        q->next = p;
        p = q;
        return p;
}

NODE deleteFront(NODE p)
{
        if(p != NULL)
        {
                int ele = p-> data;
                printf("Deleted element is %d\n", ele);
                NODE q = p->next;
                freenode(p);
                return q;
        }
        else{
                printf("Deletion not possible\n");
                return NULL;
        }
}

void display(NODE p)
{
        NODE q = p;
        while(q != NULL)
        {
                printf("%d\t", q->data);
                q = q->next;
        }
        printf("\n");
}

NODE insertRear(NODE p, int ele)
{
        if(p != NULL)
        {
                NODE q = p;
                while(q->next != NULL)
                {
                        q = q->next;
                }
                NODE r = getnode();
                r->data = ele;
                q->next = r;
                r->next = NULL;
                return p;
        }
        else{
                NODE q = getnode();
                q->next = NULL;
                q->data = ele;
                return p;
        }
}

NODE deleteRear(NODE p)
{
        NODE q = p;
        if(q == NULL)
        {
                return NULL;
        }
        else if(q-> next == NULL)
        {
                printf("Deleted element is %d\n", q->data);
                freenode(q);
                return p;
        }
        else{
                NODE prev;
                while(q->next != NULL)
                {
                        prev =q;
                        q = q->next;
                }
                printf("Deleted element is %d\n", q->data);
                prev->next = NULL;
                freenode(q);
                return p;
        }
}

int searchList(NODE p, int ele)
{
        int count = 0;
        if(p == NULL)
                return -1;
        else{
                NODE s = p;
                while(s != NULL)
                {
                        if(s->data == ele){
                                count++;
                                return count;
                        }
                        s = s->next;
                        count++;
                }
                if(s == NULL)
                        return -1;
        }
}

void main()
{
        int a, ele;
        NODE p;
        while(1)
        {
                printf("Enter 1. Insert Front\n2. Delete Front\n3.Insert Rear\n4.Delete Rear\n5. Search\n");
                scanf("%d", &a);
                switch(a)
                {
                    case 1:
                        printf("Enter the element\n");
                        scanf("%d", &ele);
                        p = insertFront(p, ele);
                        break;

                    case 2:
                        p  = deleteFront(p);
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
                        printf("Enter the element to search\n");
                        scanf("%d", &ele);
                        int count = searchList(p, ele);
                        printf("Element found at position %d\n", count);
                        break;
                    case 6:
                        display(p);
                        break;
                }
        }
}





