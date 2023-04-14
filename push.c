/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsadiq <lsadiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:49:38 by lsadiq            #+#    #+#             */
/*   Updated: 2023/04/14 20:20:05 by lsadiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pb(t_push **stack1, t_push **stack2, int flag)
{
	t_push	*head;

	head = *stack1;
	*stack1 = (*stack1)->next;
	head->next = *stack2;
	*stack2 = head;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	move_pa(t_push **stack1, t_push **stack2, int flag)
{
	t_push	*head;

	head = *stack1;
	*stack1 = (*stack1)->next;
	head->next = *stack2;
	*stack2 = head;
	if (flag == 1)
		write(1, "pa\n", 3);
}
