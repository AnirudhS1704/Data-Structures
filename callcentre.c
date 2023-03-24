#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node;
typedef struct node* Node;
struct node {
    char num[10];
    Node next;
};

Node New(char a[10]) {
    Node node = malloc(sizeof(Node));
    for(int i = 0; i < 10; i++) node->num[i] = a[i];
    node->next = NULL;
    return node;
}

Node enque(Node start, char a[10]) {
    if(strlen(a) != 10) {
        printf("invalid num! must be 10 digits\n");
        return start;
    }
    printf("added -%s-\n", a);
    if(start == NULL) return New(a);
    Node trav = start;
    while(trav->next != NULL) trav = trav->next;
    trav->next = New(a);
    return start;
}

Node deque(Node start, char* dump) {
    if(start == NULL) {
        printf("all lines cleared!\n");
        *dump = "";
        return start;
    }
    Node trav = start->next;
    for(int i = 0; i < 10; i++) dump[i] = start->num[i];
    free(start);
    return trav;
}

void display(Node start) {
    printf("[\n");
    Node trav = start;
    while(trav != NULL) {
        printf("\t%s\n", trav->num);
        trav = trav->next;
    }
    printf("]\n");
}

void main() {
    int ch; char a[10];
    Node start = NULL;
    printf("cmds : enq(1), deq(2), disp(3), exit(0)\n");
    while(1) {
        printf(">>? "); scanf("%d", &ch);
        switch(ch) {
            case 0: return;
            case 1: printf(">>num "); scanf("%s", a);
                    start = enque(start, a); break;
            case 2: start = deque(start, &a);
                    printf("num: %s cleared\n", a); break;
            case 3: display(start); break;
            default: printf("invalid cmd\n");
        }
    }
}
