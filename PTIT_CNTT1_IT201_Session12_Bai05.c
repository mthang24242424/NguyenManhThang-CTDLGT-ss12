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
Node* deleteData(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            Node* toDelete = current;
            if (current == head) {
                head = current->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
            }
            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }
    return head;
}
int main(void) {
    Node* head = createNode(1);
    Node* node1 = createNode(4);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    int value;
    printf("Nhap gia tri muon xoa:");
    scanf("%d",&value);
    head = deleteData(head,value);
    printList(head);
    return 0;
}