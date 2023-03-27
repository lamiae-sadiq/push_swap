/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:39 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/24 15:40:03 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Define a stack of linked lists
struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

// Function to push a node onto the stack
void push(struct stack* stk, int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = stk->top;
    stk->top = newnode;
}

// Function to push a stack of linked lists to another stack
void pushStack(struct stack* dest, struct stack* src) {
    struct node* curr = src->top;
    while (curr != NULL) {
        push(dest, curr->data);
        curr = curr->next;
    }
}


// Driver code
int main() {
    struct stack stk1, stk2;
    stk1.top = NULL;
    stk2.top = NULL;

    // Push some nodes onto stk1
    push(&stk1, 1);
    push(&stk1, 2);
    push(&stk1, 3);

    // Push the nodes from stk1 onto stk2
    pushStack(&stk2, &stk1);

    // Print the nodes in stk2
    printf("Stack 2: ");
    while (stk2.top != NULL) {
        printf("%d ", pop(&stk2));
    }
    printf("\n");

    return 0;
}
