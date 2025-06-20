#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer for the list
struct Node* head = NULL;

// Function to insert at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d into the list.\n", value);
}

// Function to delete a node by value
void delete(int value) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Function to traverse the list
void traverse() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate list operations
int main() {
    insert(10);
    insert(20);
    insert(30);
    traverse();

    delete(20);
    traverse();

    delete(40);  // Value not in the list

    return 0;
}
