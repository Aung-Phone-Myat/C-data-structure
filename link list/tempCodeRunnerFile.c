#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode (int newData) {
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning (struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd (struct Node** head, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode (struct Node** head, int key) {
    if (*head == NULL) {
        return;
    }
    struct Node *temp = *head, *before, *after;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        before = temp;
        temp = temp->next;
    }
    after = temp->next;
    before->next = temp->next;
    after->prev = before;
    free(temp);
}

void showData (struct Node* head) {
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head = head->next;
    }
}

void insertBefore (struct Node** head, int key, int newData) {
    struct Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head, *after;
    if (temp->data == key)
    {
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        
        return;
    }
    while (temp != NULL && temp->data !=key) {
        temp = temp->next;
    }
    after = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = after;
    after->prev = newNode;

}

void showReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    
    while (temp != NULL) {
        printf("data: %d\n", temp->data);
        temp = temp->prev;
    }
}


int main () {
    struct Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    
    showData(head);
    printf("___________\n");
    showReverse(head);
    printf("___________\n");

    deleteNode(&head, 4);
    showData(head);

    printf("___________\n");
    insertBefore(&head, 6, 10);
    showData(head);
    printf("___________\n");
}