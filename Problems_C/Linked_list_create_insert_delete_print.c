//Structure Definition
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Create a Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Insert at Head
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

//Insert at End
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Insert at Position
void insertAtPos(Node** head, int data, int pos) {
    if (pos == 0) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; ++i) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

//Delete Head Node
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

//Delete Last Node
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//Delete Node at Position
void deleteAtPos(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        deleteHead(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < pos - 1; ++i) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

//Print List
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Main code
int main() {
    Node* head = NULL;

    insertAtHead(&head, 10);
    insertAtEnd(&head, 40);
    insertAtPos(&head, 20, 1);
    insertAtPos(&head, 30, 2);
    printList(head);        // 10 -> 20 -> 30 -> 40 -> NULL

    deleteHead(&head);
    printList(head);        // 20 -> 30 -> 40 -> NULL

    deleteEnd(&head);
    printList(head);        // 20 -> 30 -> NULL

    deleteAtPos(&head, 1);
    printList(head);        // 20 -> NULL

    deleteHead(&head);
    printList(head);        // NULL

    return 0;
}

