#include<stdio.h>
#include<stdlib.h>

int n;

struct Queue{
        int *arr;
        int rear;
        int front;
};

struct Queue createQ(int n, struct Queue *q)
{
        q->arr = (int*)malloc(sizeof(int)*n);
        return *q;
}

int isFull(int rear, int front)
{
        if(rear == n-1 )
                return 1;
        return 0;
}

int isEmpty(int rear, int front)
{
        if(rear < front)
                return 1;
        return 0;
}


void insertQ(struct Queue *q, int ele)
{
        if(isFull(q->rear, q->front))
                printf("Queue full!\n");
        else{

                        q->rear++;
                        q->arr[q->rear]=ele;
                }
}

int deleteQ(struct Queue *q)
{
        if(isEmpty(q->rear, q->front))
        {
                printf("Queue full!\n");
                return -10000;
        }

        else{

                int ele =q->arr[q->front];
                q->front++;
                return ele;
        }
}

void displayQ(struct Queue *q)
{
        for(int i=q->front; i<=q->rear; i++)
        {
                printf("%d\t", q->arr[i]);
        }
        printf("\n");
}

void main()
{
        struct Queue q;
        q.front = 0;
        q.rear = -1;
        printf("Enter the no. of elements of queue\n");
        scanf("%d", &n);
        q = createQ(n, &q);
        int a, ele;
        while(1)
        {
                printf("Enter 1. Insert\n2. Delete\n 3.Dispaly\n");
                scanf("%d", &a);
                switch(a)
                {
                        case 1:
                                printf("Enter the element to insert\n");
                                scanf("%d", &ele);
                                insertQ(&q, ele);
                                break;
                        case 2:
                                ele = deleteQ(&q);
                                printf("Element deleted = %d\n", ele);
                                break;
                        case 3:
                                displayQ(&q);
                                break;
                        default:
                                break;
                }
        }
}
                      
