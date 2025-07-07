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

Node* findMid(Node* head) {
    if (head == NULL) return head;

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(void) {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;
    Node* mid = findMid(head);
    if (mid != NULL) {
        printf("phan tu o giua dslk = %d",mid->data);
    }else {
        printf("danh sach rong");
    }
    return 0;
}