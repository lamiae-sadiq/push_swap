/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:49:38 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/08 00:09:12 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_pb(t_push **stack1, t_push **stack2)
{
    //Take the first element at the top of a and put it at the top of b.Do nothing if a is empty.
    t_push *head;

    head = *stack1;
    *stack1 = (*stack1)->next;
    head->next = *stack2;
    *stack2 = head;
    printf("pb\n");
}

void    move_pa(t_push **stack1, t_push **stack2)
{
    t_push *head;

    head = *stack1;
    *stack1 = (*stack1)->next;
    head->next = *stack2;
    *stack2 = head;
    printf("pa\n");
}

// void    move_pb(t_push **stack1, t_push **stack2)
// {
// 	t_push	*tmp;

// 	if (*stack1 == NULL)
// 		return ;
// 	tmp = (*stack1)->next;
//     printf("%d\n", tmp->num);
// 	(*stack1)->next = *stack2;
// 	*stack2 = *stack1;
// 	*stack1 = tmp;
	// while((*stack1)->next)
	// {
	// 	printf("%d>>>>\n", (*stack1)->num);
	// 	*stack1 = (*stack1)->next;
	// }
	//printf("%d>>\n", (*stack2)->num);
// }
