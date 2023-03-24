#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {  // check if the list is empty
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;  // create a temporary node to hold the first node
    *head = (*head)->next;  // move the head pointer to the second node
    free(temp);  // free the memory occupied by the first node
    printf("First node deleted\n");
}

int main() {
    // create a linked list with three nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // print the original list
    struct Node* current = head;
    printf("Original List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // delete the first node and print the updated list
    deleteFirstNode(&head);
    current = head;
    printf("Updated List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
