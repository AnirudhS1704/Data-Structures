#include<stdio.h>
#define max 5

struct CQ{
        int arr[max];
        int rear;
        int front;
        int count;
};

int isFull(int count)
{
        if(count == max-1 )
                        return 1;
                return 0;
}

int isEmpty(int count)
{
        if(count ==0)
                return 1;
        return 0;
}

void insertQ(struct CQ *cq, int ele)
{
        if(isFull(cq->count))
        {
                printf("Queue full\n");
        }
        else{
                cq->rear = (cq->rear+1)%max;
                cq->arr[cq->rear]=ele;
                cq->count++;
        }
}

int deleteQ(struct CQ *cq)
{
        if(isEmpty(cq->count))
        {
                printf("Queue empty\n");
                return -10000;
        }
        else{
             int ele = cq->arr[cq->front];
                cq->front = (cq->front+1)%max;
                cq->count--;
                return ele;
        }
}

void displayQ(struct CQ *cq)
{
        for(int i=0; i<cq->count; i++)
        {
                printf("%d\t", cq->arr[cq->front]);
                cq->front = (cq->front+1)%max;
        }
        printf("\n");
}

void main()
{
        struct CQ cq;
        cq.front = 0;
        cq.rear = -1;
        int a, ele;
        while(1)
        {
                printf("Enter 1. Insert\n2. Delete\n3. Display\n");
                scanf("%d",&a);
                switch(a)
                {
                        case 1:
                                printf("Enter the element to insert\n");
                                scanf("%d", &ele);
                                insertQ(&cq, ele);
                                break;
                        case 2:
                                ele = deleteQ(&cq);
                                printf("Element deleted = %d\n", ele);
                                break;
                        case 3:
                                displayQ(&cq);
                                break;
                        default:
                                break;
                }
        }
}


