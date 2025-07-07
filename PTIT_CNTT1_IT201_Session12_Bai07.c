#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node* head) {
    printf("NULL <-");
    while (head != NULL) {
        if (head->next == NULL) {
            printf(" %d -> ",head->data);
        }else {
            printf(" %d <-->",head->data);
        }
        head = head->next;
    }
    printf("NULL\n");
}
Node* sortList(Node* head) {
    if (head == NULL) return;
    Node* i;
    Node* j;
    for (i = head; i->next != NULL; i = i->next) {
        Node* min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data) {
                min = j;
            }
        }
        if (min != i) {
            int temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
}
int main(void) {
    Node* head = createNode(4);
    Node* node1 = createNode(1);
    Node* node2 = createNode(3);
    Node* node3 = createNode(2);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;
    sortList(head);
    printList(head);
    return 0;
}