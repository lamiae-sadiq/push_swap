/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:35:10 by lsadiq            #+#    #+#             */
/*   Updated: 2023/03/26 01:06:20 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void firstlast(t_push *stack)
{
    t_push *last;
    t_push *prev = NULL;
    // t_push *tmp;
    // int temp;

    last = stack;
    // while(last->next)
    // {
    //     tmp = last;
    //     last = last->next;
    // }
    // // last->num = stack->num;
    // stack = last;
    // printf("%d\n", last->num);
    // temp = last->num; 
    // last->next = stack;
    // printf("%d>>\n", last->num);
   while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    last->next = stack;
    stack = last;
    // return stack;
    printf("rra\n");
}

// typedef struct s_push {
//     int num;
//     struct s_push *next;
// } t_push;

// typedef struct s_swap {
//     t_push *top;
// } t_swap;

// void push(t_swap *stack, int data) {
//     t_push *new_node = (t_push*)malloc(sizeof(t_push));
//     // new_node->num = num;
//     new_node->next = stack->top;
//     stack->top = new_node;
// }

// t_push *pop(t_swap *stack) {
//     if (stack->top == NULL) {
//         printf("Error: Stack underflow\n");
//         return NULL;
//     }
//     t_push *temp = stack->top;
//     stack->top = stack->top->next;
//     return temp;
// }

// void push(t_push *stack1, t_push *stack2) {
//     // Pop the top element from stack1
//     t_push *temp = pop(stack1);

//     // Push the popped element onto stack2
//     push(stack2, temp->num);

//     // Free the memory used by the popped element
//     free(temp);
// }

void	ra(t_push **stack_a, int k)
{
	t_push	*head;
	t_push	*cur;

	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return ;
	*stack_a = head->next;
	head->next = NULL;
	cur = *stack_a;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = head;
	if (k == 1)
		write(1, "ra\n", 3);
}