include<stdio.h>
#define maxsize 10
#include<stdlib.h>

struct stack{
        int ele[maxsize];
        int top;
};

int checkOverflow(int top)
{
        if(top==maxsize-1)
                return 1;
        return 0;
}

int checkUnderflow(int top)
{
        if(top==-1)
                return 1;
        return 0;
}

void push(struct stack *ptr, int n)
{
        if(checkOverflow(ptr->top))
        {
                printf("Stack Overflow\n");
        }
        else{
                ptr->top++;
                ptr->ele[ptr->top]=n;
        }
}

int pop(struct stack *ptr)
{
        if(checkUnderflow(ptr->top)){
                        printf("Stack Underflow\n");
                        return -10000;
        }
        else{
                return ptr->ele[ptr->top--];
        }
}

void display(struct stack s)
{
        for(int i=0; i<=s.top;i++)
        {
                printf("%d\t", s.ele[i]);
        }
}

void main(){
        int a, v1, v2;
        struct stack s;
        s.top=-1;
        while(1)
        {
                printf("Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
                scanf("%d",&a);
                switch(a){
                        case 1:
                                printf("Enter the element\n");
                                scanf("%d",&v1);
                                push(&s, v1);
                                break;
                        case 2:
                                v2 = pop(&s);
                                printf("Popped element is %d\n", v2);
                                break;
                        case 3:
                                display(s);
                                break;
                        case 4:
                                exit(1);
                                break;
                        default:
                                printf("Wrong choice!!");
                }
        }
}
                                                                                                                                                                                         82,1          Bot

